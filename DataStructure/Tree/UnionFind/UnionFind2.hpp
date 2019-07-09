/*
 * @Author: five-5
 * @Date: 2019-07-09 17:27:36
 * @Description: Union-find第二版，森林，底层还是数组
 * @LastEditTime: 2019-07-09 17:37:42
 */

#ifndef UNION_FIND_2_H
#define UNION_FIND_2_H

#include <stdexcept>

#include "UF.h"

class UnionFind2: public UF{
 public:
    UnionFind2(int size) : size_(size) {
        parent_ = new int[size];

        for (int i = 0; i < size; ++i) {
            parent_[i] = i;
        }
    }

    int size() override { return size_; }

    // 查看元素p和元素q是否所属一个集合
    // O(h)，h为树的高度
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    // 合并元素p和元素q所属的集合
    // O(h)，h为树的高度
    void unionElements(int p, int q) {
        int qParent = find(q);
        int pParent = find(p);

        if (qParent == pParent) {
            return;
        }

        parent_[pParent] = qParent;
    }

 private:
    int size_;
    int *parent_;

    // 查找过程，查找元素p所对应的集合编号
    // O(h)，h为树的高度
    int find(int p) {

        if (p < 0 && p >= size_) {
            throw  std::runtime_error("p is out of bound.");
        }

        while(p != parent_[p]) {
            p = parent_[p];
        }
        return p;
    }
};

#endif