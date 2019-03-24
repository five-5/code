/*
 * @Author: five-5
 * @Description: 
 * @Date: 2019-03-25
 * @LastEditTime: 2019-03-25
 */
#ifndef LINK_LIST_QUEUE_H
#define LINK_LIST_QUEUE_H

#include "queue.h"
#include <iostream>

template <typename T>
class LinkListQueue: public Queue<T> {
 public:
    LinkListQueue():head_(nullptr), tail_(nullptr), size_(0){}

    // Override
    int size() const {
        return size_;
    }

    // Override
    bool empty() const{
        return size_ == 0;
    }

    // Override
    T front() const {
        if (empty()) {
            std::cout << "Queue is empty" << std::endl;
            return T();
        }
        return head_->e_;
    }

    // Override
    T pop() {
        if (empty()) {
            std::cout << "can not pop an empty queue" << std::endl;
        }
        T ret = head_->e_;
        Node *tmp = head_;
        head_ = head_->next_;
        delete tmp;
        return ret;
    }
    
    // Override
    void push(T e) {
        if (tail_ == nullptr) {
            tail_ = new Node(e);
            head_ = tail_;
        } else{
            tail_->next_ = new Node(e);
            tail_ = tail_->next_;
        }
        ++size_;
    }
    
    friend std::ostream & operator<< (std::ostream &out, const LinkListQueue &link_list_q) {
        out << "Queue: front ";
        
        for(Node *cur = link_list_q.head_; cur != nullptr; cur = cur->next_) {
            out << cur->e_ << "->";
        }
        out << "nullptr tail";
        return out;
    }

 private:
    class Node {
        public:
            Node(T e, Node *next):e_(e), next_(next){}
            Node (T e): e_(e), next_(nullptr){}

            T e_;
            Node *next_;
            
        friend std::ostream & operator<< (std::ostream &out, const Node &e) {
            out << e.e_;
            return out;
        }
    };

 private:
    Node *head_, *tail_;
    int size_;
};
#endif