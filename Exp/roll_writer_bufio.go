// Copyright (c) 2019-present, Tencent, Inc.  All rights reserved.

// RollWriter itself does not provide log printing function, but implements the io.Writer and io.Sync interface
// So this component can work with any log package that can be written to io.Writer (including the log package of
// the standard library)
// Main features:
// 1. Support log scrolling by file size
// 2. Support log scrolling by time
// 3. Support automatic cleaning of expired or redundant log files
// 4. Support compressed log files
// 5. Support write buffer

package logger

import (
	"bufio"
	"compress/gzip"
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"sync"
	"time"

	"github.com/lestrrat-go/strftime"

	"git.code.oa.com/nosql/control_plane/pkg/common/errors"
)

const (
	backupTimeFormat = "bk-20060102-150405.000"
	compressSuffix   = ".gz"
	defaultMaxSize   = 100
)

// To decrease the times of garbage collection.
var _rollWriterPool = sync.Pool{New: func() interface{} {
	return &RollWriter{}
}}

func getRollWriter() *RollWriter {
	return _rollWriterPool.Get().(*RollWriter)
}

func putRollWriter(w *RollWriter) {
	w.filePath = ""
	w.opts = nil
	w.pattern = nil
	w.currFile = nil
	w.currPath = ""
	w.currSize = 0
	w.bufWriter = nil
	w.openTime = 0
	_rollWriterPool.Put(w)
}

// ensure we always implement io.WriteCloser
var _ io.WriteCloser = (*RollWriter)(nil)

// RollWriter also supports file log writing that roll by size and time
// Implement interface io.WriteCloser
type RollWriter struct {
	filePath string
	opts     *Options

	pattern   *strftime.Strftime
	currDir   string
	currPath  string
	currSize  int64
	currFile  *os.File
	bufWriter *bufio.Writer
	openTime  int64

	mu       sync.Mutex
	once     sync.Once
	notifyCh chan bool
	closeCh  chan *RollWriter
}

// NewRollWriter creates RollWriter
func NewRollWriter(filePath string, opt ...Option) (*RollWriter, error) {
	opts := &Options{
		MaxSize:    defaultMaxSize * 1024 * 1024, // Default is 100M.
		MaxAge:     0,                            // Do not clean up old files by default.
		MaxBackups: 0,                            // Do not delete redundant files by default.
		Compress:   false,                        // No compression by default.
		BufferSize: defaultBufferSize,
	}

	// The input parameter is the highest priority, overwrite the default data
	for _, o := range opt {
		o(opts)
	}

	if filePath == "" {
		return nil, errors.NewLogFilePathInvalid(errors.WithMsg("invalid file path"))
	}

	pattern, err := strftime.New(filePath + opts.TimeFormat)
	if err != nil {
		return nil, errors.NewLogTimeFormatInvalid(errors.WithMsg("invalid time pattern"))
	}

	w := &RollWriter{
		filePath:  filePath,
		opts:      opts,
		pattern:   pattern,
		currDir:   filepath.Dir(filePath),
		bufWriter: bufio.NewWriterSize(nil, opts.BufferSize),
	}

	err = os.MkdirAll(w.currDir, 0755)
	if err != nil {
		return nil, err
	}

	return w, nil
}

// Write implements io.Writer
func (w *RollWriter) Write(v []byte) (n int, err error) {
	// Reopen the file every 10 seconds
	if w.currFile == nil || time.Now().Unix()-w.openTime > 10 {
		w.mu.Lock()
		w.reopenFile()
		w.mu.Unlock()
	}

	// If file creation fails, it returns.
	if w.currFile == nil {
		// TODO err
		return 0, errors.NewOpenLogFileFailed(errors.WithMsg("open file failed"))
	}

	// Write log to file.
	n, err = w.bufWriter.Write(v)
	w.currSize += int64(n)

	// The file is full and start to roll.
	if w.currSize >= w.opts.MaxSize {
		w.mu.Lock()
		w.backupFile()
		w.mu.Unlock()
	}

	return n, err
}

// Close closes the current log file and implement io.Closer
func (w *RollWriter) Close() error {
	if w.currFile == nil {
		return nil
	}

	if w.bufWriter != nil {
		w.Sync()
	}

	err := w.currFile.Close()
	w.currFile = nil
	w.bufWriter = nil
	return err
}

// Sync
func (w *RollWriter) Sync() error {
	return w.bufWriter.Flush()
}

// ReopenFile reopens the file regularly. If the current file path changes, the cleanup coroutine needs to be notified.
func (w *RollWriter) reopenFile() {
	if w.currFile == nil || time.Now().Unix()-w.openTime > 10 {
		w.openTime = time.Now().Unix()
		currPath := w.pattern.FormatString(time.Now())
		if w.currPath != currPath {
			w.currPath = currPath
			w.notify()
		}
		w.doReopenFile(w.currPath)
	}
}

func (w *RollWriter) clone() *RollWriter {
	clone := getRollWriter()
	clone.openTime = w.openTime
	clone.bufWriter = w.bufWriter
	clone.currSize = w.currSize
	clone.currPath = w.currPath
	clone.currFile = w.currFile
	clone.pattern = w.pattern
	clone.opts = w.opts
	clone.filePath = w.filePath
	clone.currDir = w.currDir
	clone.notifyCh = w.notifyCh
	clone.closeCh = w.closeCh
	return clone
}

// DoReopenFile reopens the file.
func (w *RollWriter) doReopenFile(path string) error {
	w.openTime = time.Now().Unix()
	lastFile := w.clone()
	defer putRollWriter(lastFile)

	of, err := os.OpenFile(path, os.O_WRONLY|os.O_APPEND|os.O_CREATE, 0666)
	if err == nil {
		w.currFile = of
		w.bufWriter.Reset(w.currFile)

		if lastFile != nil {
			// It may still be in use and needs to be closed with a delay.
			w.closeCh <- lastFile
		}

		st, _ := os.Stat(path)
		if st != nil {
			w.currSize = st.Size()
		}
	}

	return err
}

// BackupFile backups the current file and reopen a new file, when the file exceeds the size limit.
func (w *RollWriter) backupFile() {
	if w.currSize >= w.opts.MaxSize {
		w.currSize = 0

		// Rename the old file.
		newName := w.currPath + "." + time.Now().Format(backupTimeFormat)
		if _, e := os.Stat(w.currPath); !os.IsNotExist(e) {
			os.Rename(w.currPath, newName)
		}

		// Open a new file.
		w.doReopenFile(w.currPath)
		w.notify()
	}
}

// Notify notifies the cleanup coroutine to perform cleanup actions.
func (w *RollWriter) notify() {
	w.once.Do(func() {
		w.notifyCh = make(chan bool, 1)
		w.closeCh = make(chan *RollWriter, 100)
		go w.runCleanFiles()
		go w.runCloseFiles()
	})

	select {
	case w.notifyCh <- true:
	default:
	}
}

// RunCloseFiles starts a coroutine to delay closing the log file handle
func (w *RollWriter) runCloseFiles() {
	for f := range w.closeCh {
		// Turn off with 20ms delay
		time.Sleep(20 * time.Millisecond)
		f.Close()
	}
}

// RunCleanFiles starts a coroutine to regularly clean up redundant or expired log files/compress log files.
func (w *RollWriter) runCleanFiles() {
	for range w.notifyCh {
		if w.opts.MaxBackups == 0 && w.opts.MaxAge == 0 && !w.opts.Compress {
			continue
		}

		w.cleanFiles()
	}
}

// CleanFiles cleans up redundant or expired log files/compress log files.
func (w *RollWriter) cleanFiles() {
	// Get a list of log files related to the current log.
	files, err := w.getOldLogFiles()
	if err != nil || len(files) == 0 {
		return
	}

	// Sort by time to find files to be cleaned that exceed the number of files.
	var compress, remove []logInfo
	files = filterByMaxBackups(files, &remove, w.opts.MaxBackups)

	// Find out expired files based on the last modification time of the file.
	files = filterByMaxAge(files, &remove, w.opts.MaxAge)

	// According to the extension .gz, find out the files that need to be compressed.
	filterByCompressExt(files, &compress, w.opts.Compress)

	// Delete expired or redundant log files.
	w.removeFiles(remove)

	// Compress log files that need to be compressed.
	w.compressFiles(compress)
}

// GetOldLogFiles returns the log file list related to the current log file (sorted by modification time).
func (w *RollWriter) getOldLogFiles() ([]logInfo, error) {
	files, err := ioutil.ReadDir(w.currDir)
	if err != nil {
		return nil, fmt.Errorf("can't read log file directory: %s", err)
	}

	logFiles := []logInfo{}
	filename := filepath.Base(w.filePath)
	for _, f := range files {
		if f.IsDir() {
			continue
		}

		if modTime, err := w.matchLogFile(f.Name(), filename); err == nil {
			logFiles = append(logFiles, logInfo{modTime, f})
		}
	}
	sort.Sort(byFormatTime(logFiles))

	return logFiles, nil
}

// MatchLogFile matches all log files related to the current log file, if it matches, return the file modification time.
func (w *RollWriter) matchLogFile(filename, filePrefix string) (time.Time, error) {
	// Exclude current log file.
	// a.log
	// a.log.20200712
	if filepath.Base(w.currPath) == filename {
		return time.Time{}, errors.NewMatchLogEmpty(errors.WithMsg("ignore current logfile"))
	}

	// Match all log files related to the current log file.
	// a.log -> a.log.20200712-1232/a.log.20200712-1232.gz
	// a.log.20200712 -> a.log.20200712.20200712-1232/a.log.20200712.20200712-1232.gz
	if !strings.HasPrefix(filename, filePrefix) {
		return time.Time{}, errors.NewPrefixMismatched(errors.WithMsg("mismatched prefix"))
	}

	if st, _ := os.Stat(filepath.Join(w.currDir, filename)); st != nil {
		return st.ModTime(), nil
	}

	return time.Time{}, errors.NewFileStatFailed(errors.WithMsg("file stat fail"))
}

// RemoveFiles removes expired or redundant log files.
func (w *RollWriter) removeFiles(remove []logInfo) {
	// Clean up files (expired or exceed the number of files that can be retained).
	for _, f := range remove {
		os.Remove(filepath.Join(w.currDir, f.Name()))
	}
}

// CompressFiles compresses log files that need to be compressed.
func (w *RollWriter) compressFiles(compress []logInfo) {
	// Compress log files.
	for _, f := range compress {
		fn := filepath.Join(w.currDir, f.Name())
		compressFile(fn, fn+compressSuffix)
	}
}

// FilterByMaxBackups filters out redundant log files that exceed the limit.
func filterByMaxBackups(files []logInfo, remove *[]logInfo, maxBackups int) []logInfo {
	if maxBackups < len(files) {
		return files
	}

	var remaining []logInfo
	preserved := make(map[string]bool)
	for _, f := range files {
		fn := strings.TrimSuffix(f.Name(), compressSuffix)
		preserved[fn] = true

		if len(preserved) > maxBackups {
			*remove = append(*remove, f)
		} else {
			remaining = append(remaining, f)
		}
	}
	return remaining
}

// FilterByMaxAge filters out expired log files.
func filterByMaxAge(files []logInfo, remove *[]logInfo, maxAge int) []logInfo {
	if maxAge <= 0 {
		return files
	}

	var remaining []logInfo
	diff := time.Duration(int64(24*time.Hour) * int64(maxAge))
	cutoff := time.Now().Add(-1 * diff)
	for _, f := range files {
		if f.timestamp.Before(cutoff) {
			*remove = append(*remove, f)
		} else {
			remaining = append(remaining, f)
		}
	}

	return remaining
}

// FilterByCompressExt filters out all compressed files
func filterByCompressExt(files []logInfo, compress *[]logInfo, needCompress bool) {
	if !needCompress {
		return
	}

	for _, f := range files {
		if !strings.HasSuffix(f.Name(), compressSuffix) {
			*compress = append(*compress, f)
		}
	}
}

// CompressFile compresses the incoming files, the original files will be cleaned up if the compression is successful.
func compressFile(src, dst string) (err error) {
	f, err := os.Open(src)
	if err != nil {
		return fmt.Errorf("failed to open file: %v", err)
	}
	defer f.Close()

	gzf, err := os.OpenFile(dst, os.O_CREATE|os.O_TRUNC|os.O_WRONLY, 0666)
	if err != nil {
		return fmt.Errorf("failed to open compressed file: %v", err)
	}
	defer gzf.Close()

	gz := gzip.NewWriter(gzf)
	defer func() {
		gz.Close()
		if err != nil {
			os.Remove(dst)
			err = fmt.Errorf("failed to compress file: %v", err)
		} else {
			os.Remove(src)
		}
	}()

	if _, err := io.Copy(gz, f); err != nil {
		return err
	}

	return nil
}

// logInfo is used to return the file name and last modification time.
type logInfo struct {
	timestamp time.Time
	os.FileInfo
}

// ByFormatTime sorts by time in descending order.
type byFormatTime []logInfo

// Less determines whether the time of b[j] is earlier than the time of b[j]
func (b byFormatTime) Less(i, j int) bool {
	return b[i].timestamp.After(b[j].timestamp)
}

// Swap swaps b[i] and b[j].
func (b byFormatTime) Swap(i, j int) {
	b[i], b[j] = b[j], b[i]
}

// Len returns the length of the array b.
func (b byFormatTime) Len() int {
	return len(b)
}

