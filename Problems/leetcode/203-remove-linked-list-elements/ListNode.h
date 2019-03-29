/*
 * @Author: five-5
 * @Description: Definition for singly-linked list.
 * @Date: 2019-03-29
 * @LastEditTime: 2019-03-29
 */

#ifndef LIST_NODE_H
#define LIST_NODE_H
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
};

#endif
 