/*
 * @Author: five-5
 * @Description: 自定义MyArray数据结构
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-24
 */

#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

template <typename T>
class MyArray{

 public:
    // constructor
    explicit MyArray(int capacity) : capacity_(capacity){
        data_ = new T[capacity];
        size_ = 0;
    }

    // default
    MyArray():MyArray(10) {}

    // assign
    MyArray & operator=(const MyArray &rhs) {
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        data_ = new T[capacity_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = rhs.data_[i];
        }
        return *this;
    }
    
    ~MyArray() {
        delete[] data_;
        capacity_ = 0;
        size_ = 0;
    }

    // get size
    int size() const{
        return size_;
    }

    // get capacity
    int capacity() const{
        return capacity_;
    }

    // 判断是否为空
    bool IsEmpty() const{
        return size_ == 0;
    }

    // 数组最后添加元素
    void AddLast(T e) {
        /*if (size_ == capacity_) {
            
        }
        data_[size_] = e;
        ++size_;*/
        Add(size_, e);
    }

    // 数组首部添加元素
    void AddFirst(T e) {
        Add(0, e);
    }

    // 在数组index位置添加元素
    void Add(int index, T e) {
        
        if (index < 0 || index > size_) {
            cout << "Add failed. Index is illegal." << endl;
        }

        if (size_ == capacity_) {
            Resize(2 * capacity_);  // 扩容大小与当前大小量级相同
        }
 
        for (int i = size_ - 1; i >= index; --i) {
            data_[i + 1] = data_[i];
        }
        data_[index] = e;
        ++size_;
    }

    // 获取index位置的元素
    T Get(int index) const{
        if (index < 0 || index >= size_) {
            cout << "Get failed. Index is illegal," << endl;
            return T();
        }
        return data_[index];
    }

    // 获取第一个元素
    T GetFirst() const{
        return Get(0);
    }

    // 获取最后一个元素
    T GetLast() const{
        // 不直接返回data_[size_ - 1]是因为可以利用Get中关于索引的检查
        return Get(size_ - 1);
    }


    // 获取index位置的元素
    T data(int index) const{
        if (index < 0 || index >= size_) {
            cout << "Get failed. Index is illegal." << endl;
            return -1;
        }
        return data_[index];
    }

    // 设置index位置的元素值为e
    void set_data(int index, T e) {
        if (index < 0 || index >= size_) {
            cout << "Set failed. Index is illegal." << endl;
            return;
        }
        data_[index] = e;
    }

    // 查找数组是否有元素e
    bool Contains(T e) {
        for (int i = 0; i < size_; ++i) {
            if (data_[i] == e)
                return true;
        }
        return false;
    }

    // 查找数组中元素e所在的所以，不存在返回-1
    int Find(T e) {
        for (int i = 0; i < size_; ++i) {
            if (data_[i] == e)   // 对象需重载操作符==
                return i;
        }
        return -1;
    }

    // 删除数组中index位置的元素，并返回删除元素
    T Remove(int index) {
        if (index < 0 || index >= size_) {
            cout << "Remove failed. Index is illegal" << endl;
            return T();
        }

        T ret = data_[index];
        for (int i = index + 1; i < size_; ++i) {
            data_[i-1] = data_[i];
        }
        --size_;

        // 防止复杂度震荡，lazy一点
        if ((size_ == capacity_ / 4) && (capacity_ / 2 != 0))
            Resize(capacity_ / 2);
        return ret;
    }

    // 删除数组中第一个元素，并返回删除元素
    T RemoveFirst() {
        return Remove(0);
    }

    // 删除数组中最后一个元素，并返回删除元素
    T RemoveLast() {
        return Remove(size_ - 1);
    }

    // 从数组中删除元素e
    void RemoveElement(T e) {
        int index = Find(e);
        if (index != -1) {
            Remove(index);
        }
    }

    // 重载输出<<运算符
    friend std::ostream & operator << (std::ostream &out, const MyArray &arr) {
        std::stringstream format;

        format << "Array: size = " << arr.size_ << ", capacity = " << arr.capacity_ << endl;
        out << format.str();
        out << "[";
        for (int i = 0; i < arr.size_; ++i) {
            out << arr.data_[i];
            if (i != arr.size_ - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

 private:
    void Resize(int new_capacity) {
        T *new_data = new T[new_capacity];
        T *temp = data_;
        for (int i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        data_ = new_data;
        capacity_ = new_capacity;
        delete []temp;
    }

 private:
    T *data_;
    int size_;
    int capacity_;
};
