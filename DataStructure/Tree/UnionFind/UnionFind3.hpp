/*
 * @Author: five-5
 * @Date: 2019-07-09 17:27:36
 * @Description: Union-find第三版，在第二版的基础上更新合并的策略，使节点数小的指向节点数多的根
 * @LastEditTime: 2019-07-09 17:57:12
 */

#ifndef UNION_FIND_3_H
#define UNION_FIND_3_H

#include <stdexcept>

#include "UF.h"

class UnionFind3: public UF{
 public:
    UnionFind3(int size) : size_(size) {
        parent_ = new int[size];
        sz_ = new int[size];
        
        for (int i = 0; i < size; ++i) {
            parent_[i] = i;
            sz_[i] = 1;
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

        // 根据两个元素所在树的元素个数不同判断合并方向
        // 将元素个数少的集合合并到元素个数多的集合上
        if (sz_[pParent] < sz_[qParent]) {
            parent_[pParent] = qParent;
            sz_[qParent] += sz_[pParent];
        } else {
            parent_[qParent] = pParent;
            sz_[pParent] += sz_[qParent];
        }
    }

 private:
    int size_;
    int *parent_;
    int *sz_;                // sz_[i]表示以i为根的集合中元素个数

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