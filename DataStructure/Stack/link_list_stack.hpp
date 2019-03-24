/*
 * @Author: five-5
 * @Description: 
 * @Date: 2019-03-25
 * @LastEditTime: 2019-03-25
 */
#ifndef LINK_LIST_STACK_H
#define LINK_LIST_STACK_H

#include "../LinkedList/link_list.hpp"
#include "stack.h"
#include <iostream>

template <typename T>
class LinkListStack : public Stack<T> {
 public:
    LinkListStack(){
       list = LinkList<T>();
    }
    
    // Override
    int GetSize() {
       return list.size();
    }

    // Override
    bool IsEmpty() {
       return list.empty();
    }

    // Override
    T Top() {
       return list.GetFirst();
    }

    // Override
    void Push(T e) {
       list.AddFirst(e);
    }

    // Override
    T Pop(){
       return list.RemoveFirst();
    }

    friend std::ostream & operator <<(std::ostream &out, const LinkListStack &link_list_stack) {
       out << "Stack: top ";
       out << link_list_stack.list;
       return out;
    }
    

 private:
    LinkList<T> list;
};


#endif