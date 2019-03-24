/*
 * @Author: five-5
 * @Description: 数组队列
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-24
 */

#ifndef ARRAY_QUEUE_HPP
#define ARRAY_QUEUE_HPP
#include "../Array/my_array.hpp"
#include "queue.h"

#include <iostream>

template <typename T>
class ArrayQueue: public Queue<T> {
    
 public:
    ArrayQueue(int capacity) {
        array = MyArray<T>(capacity);
    }

    ArrayQueue() {
        array = MyArray<T>();
    }

    // Override
    int size() const{
        return array.size();
    }

    // Override
    void push(T e) {
        array.AddLast(e);
    }

    // Override
    bool empty() const{
        return array.IsEmpty();
    }

    // Override
    T pop() {
        return array.RemoveFirst();
    }

    // Override
    T front() const {
        return array.GetFirst();
    }

    int capacity() {
        return array.capacity();
    }

    friend std::ostream & operator<< (std::ostream &out, const ArrayQueue<T> &array_queue) {
        out << "Queue: ";
        out << "front [";
        for (int i = 0; i < array_queue.array.size(); ++i) {
            out << array_queue.array.Get(i);
            if (i != array_queue.array.size() - 1) {
                out << ", ";
            }
        }
        out << "] tail";
        return out;
    }
    
 private:
    MyArray<T> array;
};
#endif