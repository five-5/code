/*
 * @Author: five-5
 * @Date: 2019-07-09 17:07:26
 * @Description: quick find 利用数组模拟并查集
 * @LastEditTime: 2019-07-09 17:20:37
 */

#ifndef UNION_FIND1_H
#define UNION_FIND1_H

#include <stdexcept>

#include "UF.h"

class UnionFind1 : public UF{
    public:
        
        UnionFind1(int size) : size_(size) {
            id_ = new int[size];
            
            for (int i = 0; i < size; ++i) {
                id_[i] = i;
            }
        }

        int size() override { return size_; }

        // 查看元素p和元素q是否所属一个集合 O(1)
        bool isConnected(int p, int q) override {
            return find(p) == find(q);
        }

        // 合并元素p和元素q所属的集合 O(n)
        void unionElements(int p, int q) override{
            int pid = find(p);
            int qid = find(q);

            if (pid == qid)
                return;

            for (int i = 0; i < size_; ++i) {
                if (id_[i] == pid)
                    id_[i] = qid;
            }
        }

    private:
        int size_;
        int *id_;

        // 查找元素p所对应的集合编号
        int find(int p) {
            if (p < 0 && p >= size_)
                throw new std::runtime_error("p is out of bound.");
            return id_[p];
        }
};

#endif