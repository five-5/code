/*
 * @Author: five-5
 * @Description: stack interface
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-30
 */

#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
 public:
    virtual void push(T) = 0;
    virtual T pop() = 0;
    virtual T top() = 0;
    virtual int size() = 0;
    virtual bool empty() = 0; 
};
#endif