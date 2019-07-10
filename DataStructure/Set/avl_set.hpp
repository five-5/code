/*
 * @Author: five-5
 * @Date: 2019-07-10 22:29:53
 * @Description: Implementation set with avl
 * @LastEditTime: 2019-07-10 22:34:38
 */

#ifndef AVL_SET_H
#define AVL_SET_H

#include "set.h"
#include "../Tree/AVL/AVL.hpp"

template <typename K, typename V>
class AVLSet: public set<K> {
 private:
        AVL_tree::AVL<K, V> *avl;
public:
    AVLSet() {
        avl = new AVL_tree::AVL<K, V>();
    }
    ~AVLSet() {
        delete avl;
    }

    void add(K key) override {
         avl->Add(key, V());
    }
    
    void remove(K key) override {
         avl->Remove(key);
    }
    
    bool contains(K key) override {
         return avl->Contains(key);
    }
    
    int size() override {
         return avl->size();
    }
    
    bool empty() override {
         return avl->size() == 0;
    }
};

#endif 