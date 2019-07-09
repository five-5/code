/*
 * @Author: five-5
 * @Date: 2019-07-09 16:20:51
 * @Description: 
 * @LastEditTime: 2019-07-09 16:37:13
 */
/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 */
class MapSum {
 private:
    class Node{
        public:
            int val_;
            std::map<char, Node*> *next_;
            Node(int val) : val_(val), next_(new std::map<char, Node*>) {}
            Node() : Node(0) {}
            ~Node(){delete next_;}
    };
    
    Node *root_;
    
 public:
    /** Initialize your data structure here. */
    MapSum() {
        root_ = new Node();
    }
    
    void insert(string key, int val) {
        if (key.size() == 0) 
            return;
            
        Node *cur = root_;
        for (auto i = 0; i < key.size(); ++i) {
            char c = key.at(i);
            if (cur->next_->find(c) == cur->next_->end()) {
                cur->next_->emplace(c, new Node());
            }
            cur = cur->next_->at(c);
        }
        cur->val_ = val;
    }
    
    int sum(string prefix) {
        if (prefix.size() == 0)
            return 0;
        Node *cur = root_;
        for (auto i = 0; i < prefix.size(); ++i) {
            char c = prefix.at(i);
            if (cur->next_->find(c) == cur->next_->end()) {
                return 0;
            }
            cur = cur->next_->at(c);
        }

        return sum(cur);
    }

 private:
    int sum(Node *node) {
        int res = node->val_;
        for (auto it = node->next_->begin(); it != node->next_->end(); ++it) {
            res += sum(node->next_->at(it->first));
        }

        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

