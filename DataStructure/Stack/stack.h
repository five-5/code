/*
 * @Author: five-5
 * @Description: stack interface
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-24
 */

template <typename T>
class Stack {
 public:
    virtual void Push(T) = 0;
    virtual T Pop() = 0;
    virtual T Top() = 0;
    virtual int GetSize() = 0;
    virtual bool IsEmpty() = 0; 
};