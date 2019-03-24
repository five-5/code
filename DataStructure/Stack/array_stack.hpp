/*
 * @Author: five-5
 * @Description: 
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-25
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
    int GetSize() {
        return array.size();
    }

    // Override
    bool IsEmpty() {
        return array.IsEmpty();
    }

    int capacity() {
        return array.capacity();
    }

    // Override
    void Push(T e) {
        array.AddLast(e);
    }

    // Override
    T Pop() {
        return array.RemoveLast();
    }

    // Override
    T Top() {
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