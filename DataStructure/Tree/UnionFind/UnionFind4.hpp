/*
 * @Author: five-5
 * @Date: 2019-07-09 17:27:36
 * @Description: Union-find第四版，更新合并的策略，使节点高度小的指向节点高度多的根
 * @LastEditTime: 2019-07-09 19:21:24
 */

#ifndef UNION_FIND_4_H
#define UNION_FIND_4_H

#include <stdexcept>

#include "UF.h"

class UnionFind4: public UF{
 public:
    UnionFind4(int size) : size_(size) {
        parent_ = new int[size];
        rank_ = new int[size];
        
        for (int i = 0; i < size; ++i) {
            parent_[i] = i;
            rank_[i] = 1;
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

        // 根据两个元素所在树的rank_不同判断合并方向
        // 将rank_低的集合合并到rank_高的集合上
        if (rank_[pParent] < rank_[qParent]) {  // 高度 <= 子树，所以rank_值不用改变
            parent_[pParent] = qParent;
        } else if (rank_[qParent] < rank_[pParent]){
            parent_[qParent] = pParent;            
        } else {
            parent_[qParent] = pParent;
            rank_[pParent] += 1;
        }
    }

 private:
    int size_;
    int *parent_;
    int *rank_;                // rank_[i]表示以i为根的集合中元素的高度

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