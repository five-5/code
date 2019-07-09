<!--
 * @Author: five-5
 * @Date: 2019-07-09 15:09:56
 * @Description: 若干个
 * @LastEditTime: 2019-07-09 16:51:19
 -->
# Trie[前缀、字典树]
一般用来处理字符串

## 概要讲解
**字典**

如果有n个条目，使用树结构，查询的时间复杂度为O(logn)，100万个条目（2^20）

**Trie**

查询每个条目的时间复杂度只与查询单词的长度相关O(w)，大多数单词长度不超过10个

## 结点定义
每个节点有26()个指向下个节点的指针（考虑不同的语言，不同的情境）
``` c++
class Node{
    // 是否是单词的结尾
    bool isWord;
    // 只能处理26个字母
    // Node next[26];
    // 处理内容更灵活
    Map<char, Node> next;
};
```
**操作**
``` c++
void insert(const std::string &word);
bool contains(const std::string &word);
bool isPrefix(const std::string &prefix);
```

## 应用
1. leetcode208：简单的Trie的实现
2. leetcode211：字符为'.'为通配符的search实现
3. leetcode677：求以当前前缀为单词所有权重和

**拓展**
1. 删除操作

    ① 是叶子结点，则查找到最后一个字符后，自底向上的删除所有next_为空的结点。

    ② 不是叶子结点，将isWord_改为false
2. 局限性
空间太多

    -> Compressed Trie 压缩字典树（将单链存为一个node）：维护成本更高

    -> Ternary Search Trie 三分搜索Trie
    （>d =d <d）

    -> 后缀树（字符串模式识别）

3. 更多字符串问题
    - 子串查询：KMP、Boyer-Moore、Rabin-Karp
    - 文件压缩：哈弗曼树
    - 模式匹配：正则表达式的引擎
    - 编译原理
    - DNA：超长字符串（4种嘌呤）