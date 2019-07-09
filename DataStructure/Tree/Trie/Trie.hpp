/*
 * @Author: five-5
 * @Date: 2019-07-04 23:27:13
 * @Description: define and implementation of Trie
 * @LastEditTime: 2019-07-09 15:56:22
 */

#ifndef TRIE_HPP
#define TRIE_HPP

#include <map>
#include <string>
#include <stdexcept>

class Trie
{
 private:
    class Node{
        public:
            bool isWord_;
            std::map<char, Node*> *next_;
            Node(bool isWord) : isWord_(isWord), next_(new std::map<char, Node*>) {}
            Node() : isWord_(false), next_(new std::map<char, Node*>){}
            ~Node(){delete next_;}
    };
    
    Node *root_;
    int size_;

 public:
    Trie() {
        root_ = new Node();
        size_ = 0;
    }

    ~Trie() {
        if (root_ != nullptr)
            delete root_;
    }

    // 获得Trie中存储的单词数量
    int size() { return size_; }

    // 向Trie中添加一个新的单词word
    void add(const std::string &word) {
        Node *cur = root_;
        for (auto i = 0; i < word.size(); ++i) {
            char c = word.at(i);
            
            if (cur->next_->find(c) == cur->next_->end()){ // map中未查到c
                cur->next_->emplace(c, new Node()); 
            }
            cur = cur->next_->at(c); // map[c] 到下一个结点处
        }
        if (!cur->isWord_) {
            cur->isWord_ = true;
            ++size_;
        }
    }

    // 查询单词word是否在Trie中
    bool contains(const std::string &word) {
        Node *cur = root_;
        for (auto i = 0; i < word.size(); ++i) {
            char c = word.at(i);
            if ( cur->next_->find(c) == cur->next_->end()){
                return false;
            }
            cur = cur->next_->at(c);
        }
        return cur->isWord_;
    }

    // 查询是否在Trie中有单词以prefix为前缀
    bool isPrefix(const std::string &prefix) {
        Node *cur = root_;
        for (auto i = 0; i < prefix.size(); ++i) {
            char c = prefix.at(i);
            if (cur->next_->find(c) == cur->next_->end()) {
                return false;
            }
            cur = cur->next_->at(c);
        }
        return true;
    }

};

#endif