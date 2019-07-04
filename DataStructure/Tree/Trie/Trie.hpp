
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
            Node() : isWord_(false), next_(nullptr){}
            ~Node(){if(next_ != nullptr) delete next_;}
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
        for (int i = 0; i < word.size(); ++i) {
            char c = word.at(i);
            try{
                cur->next_->at(c);
            } catch(std::out_of_range e) {
                cur->next_->emplace(c, new Node());
            }
            cur = cur->next_->at(c);
        }
        if (!cur->isWord_) {
            cur->isWord_ = true;
            ++size_;
        }
    }

    // 查询单词word是否在Trie中
    bool contains(const std::string &word) {
        Node *cur = root_;
        for (int i = 0; i < word.size(); ++i) {
            char c = word.at(i);
            try{
                cur->next_->at(c);
            } catch(std::out_of_range e) {
                return false;
            }
            cur = cur->next_->at(c);
        }
        return cur->isWord_;
    }

};

#endif