/*
 * @Author: five-5
 * @Description: 
 * @Date: 2019-04-02
 * @LastEditTime: 2019-04-02
 */
#include "../LinkedList/link_list.hpp"
#include "set.h"

template <typename T>
class LinkedListSet: public set<T> {
 public:
    LinkedListSet() {
        list = new LinkList<T>();
    }

    int size() override{
        return list->size();
    }

    bool empty() override{
        return list->empty();
    }

    bool contains(T e) override{
        return list->Contains(e);
    }

    void add(T e) override{
        if (!list->Contains(e))
            list->AddFirst(e);
    }

    void remove(T e) override{
        list->Remove(e);
    }

 private: 
    LinkList<T> *list;
};