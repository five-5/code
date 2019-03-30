/*
 * @Author: five-5
 * @Description: The implementation of array-stack
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-30
 */

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include "stack.h"
#include "../Array/my_array.hpp"

#include <iostream>

template <typename T>
class ArrayStack: public Stack<T>
{
 public:
    ArrayStack(int capacity) {
        array = MyArray<T>(capacity);
    }

    ArrayStack() {
        array = MyArray<T>();
    }

    // Override
    int size() override{
        return array.size();
    }

    // Override
    bool empty() override{
        return array.IsEmpty();
    }

    int capacity() {
        return array.capacity();
    }

    // Override
    void push(T e) override{
        array.AddLast(e);
    }

    // Override
    T pop() override{
        return array.RemoveLast();
    }

    // Override
    T top() override{
        return array.GetLast();
    }

    friend std::ostream & operator<< (std::ostream &out, const ArrayStack<T> &array_stack) {
        out << "Stack: ";
        out << "[";
        for (int i = 0; i < array_stack.array.size(); ++i) {
            out << array_stack.array.Get(i);
            if (i != array_stack.array.size() - 1) {
                out << ", ";
            }
        }
        out << "] top";
        return out;
    }

 private:
    MyArray<T> array;
};
#endif