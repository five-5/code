/*
 * @Author: five-5
 * @Description: the interface of set
 * @Date: 2019-04-02
 * @LastEditTime: 2019-04-02
 */

#ifndef SET_H
#define SET_H
template <typename T>
class set{
 public:
    virtual void add(T e) = 0;
    virtual void remove(T e) = 0;
    virtual bool contains(T e) = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
};
#endif