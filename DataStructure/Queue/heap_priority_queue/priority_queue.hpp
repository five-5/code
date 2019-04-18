/*
 * @Author: five-5
 * @Description: 优先队列
 * @Date: 2019-04-17
 * @LastEditTime: 2019-04-17
 */
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "../queue.h"
#include "max_heap.hpp"

template <typename T>
class PriorityQueue: public Queue<T> {
 public:
    PriorityQueue() {
        data_ = new MaxHeap<T>();
    }

    int size() const override{
        return data_->size();
    }

    bool empty() const override{
        return data_->empty();
    }

    void push(T e) override{
        data_->add(e);
    }

    T pop() override{
        return data_->ExtractMax();
    }

    T front() const override{
        return data_->FindMax();
    }

 private:
    MaxHeap<T> *data_;
};
#endif