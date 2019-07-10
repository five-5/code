/*
 * @Author: five-5
 * @Date: 2019-07-10 22:13:43
 * @Description: implementation of map with avl
 * @LastEditTime: 2019-07-10 22:26:49
 */

#ifndef AVL_MAP_H
#define AVL_MAP_H

#include "map.h"
#include "../Tree/AVL/AVL.hpp"

template <typename K, typename V>
class AVLMap: public Map<K, V>{
 private:
        AVL_tree::AVL<K, V> *avl;
public:
    AVLMap() {
        avl = new AVL_tree::AVL<K, V>();
    }
    ~AVLMap() {
        delete avl;
    }
    void add(K key, V value) override {
        avl->Add(key, value);
    } 
    
    V remove(K key) override {
        return avl->Remove(key);
    }

    bool contains(K key) override {
        return avl->Contains(key);
    }

    V get(K key) override {
        return avl->get(key);
    }

    void set(K key, V value) override {
        avl->set(key, value);
    }
    
    int size() override {
        return avl->size();
    }
    
    bool empty() override {
        return avl->size() == 0;
    }
};

#endif 