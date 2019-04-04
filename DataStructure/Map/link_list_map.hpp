/*
 * @Author: five-5
 * @Description: implementation of map with link list
 * @Date: 2019-04-02
 * @LastEditTime: 2019-04-04
 */
#ifndef LINK_LIST_MAP_H
#define LINK_LIST_MAP_H
#include <iostream>
#include "map.h"

template <typename K, typename V>
class LinkListMap: public Map<K, V>{
 public:
    LinkListMap(){
        dummy_head_ = new Node();
        size_ = 0;
    }

    int size() override {
        return size_;
    }

    bool empty() override{
        return size_ == 0;
    }

    bool contains(K key) override{
        return get_node(key) != nullptr;
    }

   V get(K key) override{
       Node *node  = get_node(key);
       return (node == nullptr)? V() : node->value_;
    }

   /// 设计惯例 
   void add(K key, V value) override{
       Node *node = get_node(key);
       if (node == nullptr) {
           dummy_head_->next_ = new Node(key, value, dummy_head_->next_);
           ++size_;
       } else {  /// 重复地key更新value的值，而不是报错
           node->value_ = value;
       }
    }
   
    void set(K key, V new_value) override{
        Node *node = get_node(key);
       if (node == nullptr) {
           std::cout << key << " doesn't exist" << std::endl;
       }
       node->value_ = new_value;
    }


    V remove(K key) override {
        Node *prev = dummy_head_;
        while (prev->next_ != nullptr) {
            if (prev->next_->key_ == key) {
                break;
            }
            prev = prev->next_;
        }

        if (prev->next_ != nullptr) {
            Node *del_node = prev->next_;
            prev->next_ = del_node->next_;
            V ret = del_node->value_;
            delete del_node;
            --size_;
            return ret;
        }

        return V();
    }

    friend std::ostream& operator<< (std::ostream& out, const LinkListMap& map) {
        out << "LinkListMap: " << std::endl;
        Node *cur = map.dummy_head_->next_;
        while (cur != nullptr) {
            out << *cur << std::endl;
            cur = cur->next_;
        }
        return out;
    }

 private:
    
    class Node {
        public:
            K key_;
            V value_;
            Node *next_;
            Node(K key, V value, Node *next):key_(key), value_(value), next_(next){}
            Node (K key): key_(key), value_(V()), next_(nullptr){}
            Node (): key_(K()), value_(V()), next_(nullptr){}
            
        friend std::ostream & operator<< (std::ostream &out, const Node &e) {
            out << "[" << e.key_ << "] = " << e.value_;
            return out;
        }
    };

    Node *dummy_head_;
    int size_;

    Node *get_node(K key) {
        Node *cur = dummy_head_->next_;
        while (cur != nullptr) {
            if (cur->key_ == key) {       /// TODO:要不要把这个比较包装一下方法？ eg. compare
                return cur;
            }
            cur = cur->next_;
        }
        return nullptr;
    }
};

#endif