/*
 * @Author: five-5
 * @Description: 循环队列
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-24
 */
#ifndef LOOP_QUEUE_HPP
#define LOOP_QUEUE_HPP
#include "queue.h"

template <typename T>
class LoopQueue: public Queue<T> {
 public:
    LoopQueue(int capacity) {
        data_ = new T[capacity + 1];
        size_ = 0;
        front_ = tail_ = 0;
        capacity_ = capacity + 1;
    }

    LoopQueue(): LoopQueue(10){}
    
    int capacity() const{
        return capacity_ - 1;
    }

    // Override
    int size() const{
        return size_;
    }

    // Override
    bool empty() const{
        return front_ == tail_;
    }

    // Override
    void push(T e) {
        // 扩容
        if ((tail_ + 1) % capacity_ == front_) {
            resize(capacity() * 2);
        }
        data_[tail_] = e;
        tail_ = (tail_ + 1) % capacity_;
        ++size_;
    }

    // Override
    T pop() {
        if (empty()) {
            cout << "Pop failed: can not pop element from empty queue." << endl;
            return T();
        }
        T ret = data_[front_];
        front_ = (front_ + 1) % capacity_;
        --size_;

        // 缩容
        if (size_ == capacity() / 4 && capacity() / 2 != 0)
            resize(capacity()/2);
        return ret;
    }

    // Override
    T front() const{
        if (empty()) {
            std::cout << "Queue is empty." << std::endl;
            return T();
        }
        return data_[front_];
    }

 friend std::ostream & operator<< (std::ostream &out, const LoopQueue<T> &loop_queue) {
        out << "Queue: size = " << loop_queue.size() << ", capacity = " << loop_queue.capacity() << std::endl;
        out << "front [";
        for (int i = loop_queue.front_; i != loop_queue.tail_; i = (i + 1) % loop_queue.capacity_) {
            out << loop_queue.data_[i];
            if ((i + 1) % loop_queue.capacity_ != loop_queue.tail_) {
                out << ", ";
            }
        }
        out << "] tail";
        return out;
    }

 private:
    void resize(int new_capacity) {
        T *new_data = new T[new_capacity + 1];
        for (int i = 0; i < size_; ++i) {
            new_data[i] = data_[(i + front_) % capacity_];
        }
        T *temp = data_;
        data_ = new_data;
        delete []temp;
        capacity_ = new_capacity + 1;
        front_ = 0;
        tail_ = size_;
    }   

 private:
    T *data_;
    int front_, tail_;
    int size_;
    int capacity_;
};
#endif