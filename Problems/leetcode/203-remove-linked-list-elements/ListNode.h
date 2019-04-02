/*
 * @Author: five-5
 * @Description: Definition for singly-linked list.
 * @Date: 2019-03-29
 * @LastEditTime: 2019-03-29
 */

#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <iostream>

class ListNode {
 public:
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
      
      // 链表结点的构造函数
      ListNode(int *begin, int *end) {
            if (begin == end) {
                  ListNode(-1);
            }

            // this为构造的头结点
            this->val = *begin;
            ListNode *cur = this;
            for (int *first = begin + 1; first != end; ++first) {
                  cur->next = new ListNode(*first);
                  cur = cur->next;
            }
      }

      friend std::ostream & operator<<(std::ostream &out, const ListNode *list) {
            if (list == nullptr) {
                  out << "nullptr";
                  return out;
            }
            while (list != nullptr) {
                  out << list->val << "->";
                  list = list->next;
            }
            out << "nullptr";
            return out;
      }

};

#endif
 