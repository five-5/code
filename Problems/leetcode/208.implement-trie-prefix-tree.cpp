/*
 * @Author: five-5
 * @Date: 2019-07-09 15:12:21
 * @Description: leetcode208
 * @LastEditTime: 2019-07-09 15:58:15
 */
/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
class Trie {
 private:
    class Node{
        public:
            bool isWord_;
            std::map<char, Node*> *next_;
            Node(bool isWord) : isWord_(isWord), next_(new std::map<char, Node*>) {}
            Node() : isWord_(false), next_(new std::map<char, Node*>){}
            ~Node(){delete next_;}
    };

    Node* root_;

 public:
    /** Initialize your data structure here. */
    Trie() {
        root_ = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.size() == 0)
            return;
        Node* cur = root_;
        for (auto i = 0; i < word.size(); ++i) {
            char c = word.at(i);
            if (cur->next_->find(c) == cur->next_->end()) {
                cur->next_->emplace(c, new Node());
            } 
            cur = cur->next_->at(c);
        }
        
        cur->isWord_ = true;    
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.size() == 0)
            return false;
        Node* cur = root_;
        for (auto i = 0; i < word.size(); ++i) {
            char c = word.at(i);
            if (cur->next_->find(c) == cur->next_->end()) {
                return false;
            }
            cur = cur->next_->at(c);
        }

        return cur->isWord_;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix.size() == 0)
        return false;
         Node* cur = root_;
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

