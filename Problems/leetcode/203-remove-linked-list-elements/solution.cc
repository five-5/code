/*
 * @Author: five-5
 * @Description: the solution of 203
 * @Date: 2019-03-29
 * @LastEditTime: 2019-03-29
 */

#include <iostream>
#include <iterator>

#include "ListNode.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }

        // no dummy head
        // 1.deal head node
        /*while (head != nullptr && head->val == val) {
            ListNode *delNode = head;
            head = head->next;
            delete delNode;
            delNode = nullptr;
        }

        if (head == nullptr) {
            return nullptr;
        }*/

        // dummy head
        ListNode *dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode *pre = dummy_head;
        while (pre->next) {
            if (pre->next->val == val) {
                ListNode *delNode = pre->next;
                pre->next = pre->next->next;
                delete delNode;
                delNode = nullptr;
            } else {
                pre = pre->next;
            }
        }
        return dummy_head->next;
    }
};

int main() 
{
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    ListNode *head = new ListNode(std::begin(arr), std::end(arr));
    std::cout << head << std::endl;

    Solution solu;
    ListNode *result = solu.removeElements(head, 6);
    std::cout << result << std::endl;
    

    return 0;
}