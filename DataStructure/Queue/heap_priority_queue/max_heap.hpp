/*
 * @Author: five-5
 * @Description: 利用数组实现最大堆 
 * @Date: 2019-04-17
 * @LastEditTime: 2019-04-17
 */

#ifndef MAX_HEAP_H
#define MAX_HEAP_H
#include <stdexcept>
#include "../../Array/my_array.hpp"

template <typename T>
class MaxHeap{
 public:
    MaxHeap(){
        data_ = new MyArray<T>();
    }
    MaxHeap(int capacity) {
        data_ = new MyArray<T>(capacity);
    }

    MaxHeap(const std::vector<int> &arr) {
        data_ = new MyArray<T>(arr);
        for (int i = parent(data_->size() - 1); i >= 0; --i) {
            SiftDown(i);
        }
    }

    // 返回堆中的元素个数
    int size() {
        return data_->size();
    }

    // 返回一个布尔值，表示堆中是否为空
    bool empty() {
        return data_->IsEmpty();
    }

    // 向堆中添加元素
    void add(T e) {
        data_->AddLast(e);
        SiftUp(data_->size() - 1);
    }

    // 看堆中最大的元素
    T FindMax() {
        if (data_->size() == 0) {
            throw std::invalid_argument("Can not FindMax when heap is empty.");
        }
        return data_->Get(0);
    }

    // 取出堆中最大的元素
    T ExtractMax() {
        T ret = FindMax();
        data_->swap(0, data_->size() - 1);
        data_->RemoveLast();
        SiftDown(0);
        return ret;
    }

    // 取出堆中的最大元素，并且替换成元素e
    T replace(T e) {
        T ret = FindMax();
        data_->set_data(0, e);
        // 与左右孩子比较，与其中最大的交换位置
        SiftDown(0);
        return ret;
    }

    

 private:
    // 返回完全二叉树的数组表示中，一个索引所表示的元素的父亲节点的索引
    int parent(int index) {
        if (index == 0) {
            throw std::invalid_argument("index-0 doesn't have parent.");
        }
        return (index - 1) / 2;
    }   

    // 返回完全二叉树数组表示中，一个索引所表示的元素的左孩子节点的索引
    int LeftChild(int index) {
        return 2 * index + 1;
    }

    // 返回完全二叉树数组表示中，一个索引所表示的元素的右孩子节点的索引
    int RightChild(int index) {
        return 2 * index + 2;
    }

    // 上浮
    void SiftUp(int k) {
        while (k > 0 && data_->Get(k) > data_->Get(parent(k))) {
            data_->swap(k, parent(k));
            k = parent(k);
        }
    }

    // 下沉
    void SiftDown(int k) {
        while (LeftChild(k) < data_->size()) {

            int j = LeftChild(k);
            // 判断有无右孩子并且比较两者大小
            if (j + 1 < data_->size() && data_->Get(RightChild(k)) > data_->Get(LeftChild(k))) {
                j = RightChild(k);
            }

            if (data_->Get(k) >= data_->Get(j)) {
                break;
            }
            
            // data_[j]中存储左右孩子中最大值
            data_->swap(k, j);
            k = j;
        }
    }
    
 private:
    MyArray<T> *data_;
};

#endif