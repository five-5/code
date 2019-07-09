/*
 * @Author: five-5
 * @Date: 2019-07-09 16:01:59
 * @Description: leetcode211
 * @LastEditTime: 2019-07-09 16:16:28
 */
#/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 */
class WordDictionary {
private:
    class Node{
        public:
            bool isWord_;
            std::map<char, Node*> *next_;
            Node(bool isWord): isWord_(isWord), next_(new std::map<char, Node*>) {}
            Node(): isWord_(false), next_(new std::map<char, Node*>) {}
            ~Node(){delete next_;}
    };

    Node *root_;

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root_ = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if (word.size() == 0)
        return;
        Node *cur = root_;
        for (auto i = 0; i < word.size(); ++i) {
            char c = word.at(i);
            if (cur->next_->find(c) == cur->next_->end()) {
                cur->next_->emplace(c, new Node());
            }
            cur = cur->next_->at(c);
        }
        cur->isWord_ = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return match(root_, word, 0);
    }

 private:
    bool match(Node *node, const std::string &word, int index) {
        if (index == word.size()) {
            return node->isWord_;
        }

        char c = word.at(index);
        if (c != '.') {
            if (node->next_->find(c) == node->next_->end()) {
                return false;
            } else {
                return match(node->next_->at(c), word, index + 1);
            }
        } else { // 为字符'.'
            for (auto it = node->next_->begin(); it != node->next_->end(); ++it) {
                if (match(node->next_->at(it->first), word, index + 1)) {
                    return true;
                }
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

