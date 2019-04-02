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
        while (head != nullptr && head->val == val) {
            ListNode *delNode = head;
            head = head->next;
            delete delNode;
            delNode = nullptr;
        }

        if (head == nullptr) {
            return nullptr;
        }
    
        ListNode *pre = head;
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
        return head;
    }

    ListNode* removeElementsWithDummy(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }

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

    ListNode* removeElementsRecursive(ListNode* head, int val) {
        if (head == nullptr) {
            return nullptr;
        }

        head->next = removeElementsRecursive(head->next, val);
        return (head->val == val )? head->next : head;
    }

    ListNode* removeElementsRecursiveDebug(ListNode* head, int val, int depth) {
        std::string depth_string = GenerateDepthString(depth);

        std::cout << depth_string;
        std::cout << "Call: remove " << val << " in " << head << std::endl;

        if (head == nullptr) {
            std::cout << depth_string;
            std::cout << "Return: nullptr" << std::endl;
            return nullptr;
        }
        ListNode *res = removeElementsRecursiveDebug(head->next, val, depth + 1);
        ListNode *ret = nullptr;
        if (head->val == val){
            ret = res;
        } else {
            head->next = res;
            ret = head;
        }

        std::cout << depth_string;
        std::cout << "After: remove " << val << ": " << res << std::endl;
        return ret;
    }

 private:
    std::string GenerateDepthString(int depth) {
        std::string ret;
        for (int i = 0; i < depth; ++i){
            ret += '-';
        }
        return ret;
    }
};

int main() 
{
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    Solution solu;

    std::cout << "removeElementsRecursive" << std::endl;
    ListNode *head = new ListNode(std::begin(arr), std::end(arr));
    std::cout << "origin: " << head << std::endl;
    ListNode *result = solu.removeElementsRecursive(head, 6);
    std::cout << "removed: " << result << std::endl;
    
    std::cout << "removeElements" << std::endl;
    head = new ListNode(std::begin(arr), std::end(arr));
    std::cout << "origin: " << head << std::endl;
    result = solu.removeElements(head, 6);
    std::cout << "removed: " << result << std::endl;

    std::cout << "removeElementsWithDummy" << std::endl;
    head = new ListNode(std::begin(arr), std::end(arr));
    std::cout << "origin: " << head << std::endl;
    result = solu.removeElementsWithDummy(head, 6);
    std::cout << "removed: " << result << std::endl;

    std::cout << "removeElementsRecursiveDebug" << std::endl;
    head = new ListNode(std::begin(arr), std::end(arr));
    std::cout << "origin: " << head << std::endl;
    result = solu.removeElementsRecursiveDebug(head, 6, 1);
    std::cout << "removed: " << result << std::endl;

    return 0;
}