/*
 * @Author: five-5
 * @Description: addTwoNumbers
 * @Date: 2019-03-28
 * @LastEditTime: 2019-03-29
 */
#include <iostream>
using namespace std;

/**
Definition for singly-linked list.*/
  struct ListNode {
        int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);
         ListNode *head = result;
        int inc = 0;
        
        while (l1 && l2) {
            ListNode *node = new ListNode((l1->val + l2->val + inc) % 10);
            inc = (l1->val + l2->val + inc) / 10;
            result->next = node;
            result = result->next;
            l1 = l1->next;
            l2 = l2->next;
            cout << "inc = " << inc << " node = " << node->val << endl;
        }
       
       if (inc == 0) {
           if (l1) {
               result->next = l1;
           }

            if (l2) {
                result->next = l2;
            }
       } else {
           while (l1) {
               ListNode *node = new ListNode((l1->val +  inc) % 10);
                
                inc = (l1->val + inc) / 10;
                result->next = node;
                result = result->next;
                l1 = l1->next;
           }
           
           while (l2) {
               ListNode *node = new ListNode((l2->val +  inc) % 10);
                
                inc = (l2->val + inc) / 10;
                result->next = node;
                result = result->next;
                l2 = l2->next;
           }
       }
        
        if (inc == 1) {
             ListNode *node = new ListNode(inc);
            result->next = node;
        }
       
        
        return head->next;
    }
};

int main()
{
    Solution so;
    ListNode *tmp = nullptr;
    ListNode *list1 = new ListNode(2);
    tmp = list1;
    tmp->next = new ListNode(4);
    tmp = tmp->next;
    tmp->next = new ListNode(3);

    ListNode *list2 = new ListNode(5);
    tmp = list2;
    tmp->next = new ListNode(6);
    tmp = tmp->next;
    tmp->next = new ListNode(4);

    ListNode *result = so.addTwoNumbers(list1, list2);
    while(result->next != nullptr) {
        cout << result->val << "->" << endl;
        result = result->next;
    }
    cout << result->val << endl;

    return 0;
}