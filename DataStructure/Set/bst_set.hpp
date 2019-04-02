/*
 * @Author: five-5
 * @Description: Implementation set with bst
 * @Date: 2019-04-02
 * @LastEditTime: 2019-04-02
 */
#include "../Tree/Binary Search Tree/BSTRecur.hpp"
#include "set.h"

template <typename T>
class BSTSet:public set<T> {
 public:
    BSTSet(){
        bst = new BST<T>();
    }

    void add(T e) override{
        bst->Add(e);
    }

    void remove(T e) override{
        bst->Remove(e);
    }

    bool contains(T e) override{
        return bst->Contains(e);
    }

    int size() override{
        return bst->size();
    }

    bool empty() override{
        return bst->empty();
    }

 private:
    BST<T> *bst;
};