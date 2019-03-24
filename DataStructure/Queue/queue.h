/*
 * @Author: five-5
 * @Description: 
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-24
 */

#ifndef QUEUE_H
#define QUEUE_H
template <typename T>
class Queue {
 public:
    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual void push(T e) = 0;
    virtual T pop() = 0;
    virtual T front() const = 0;
};
#endif