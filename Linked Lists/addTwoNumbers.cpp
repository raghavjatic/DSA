/*
 * Problem: Add Two Numbers
 * Description: You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 *
 * Link: https://leetcode.com/problems/add-two-numbers/
 *
 * Author: Raghav Jatic
 * Date: 1st September 2025
 */

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy.next;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example 1: (2 -> 4 -> 3) + (5 -> 6 -> 4) = (7 -> 0 -> 8)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "Input: ";
    printList(l1);
    cout << " + ";
    printList(l2);

    ListNode* result = sol.addTwoNumbers(l1, l2);
    cout << "Output: ";
    printList(result);

    // Example 2: (9 -> 9 -> 9) + (1) = (0 -> 0 -> 0 -> 1)
    ListNode* l3 = new ListNode(9);
    l3->next = new ListNode(9);
    l3->next->next = new ListNode(9);

    ListNode* l4 = new ListNode(1);

    cout << "\nInput: ";
    printList(l3);
    cout << " + ";
    printList(l4);

    ListNode* result2 = sol.addTwoNumbers(l3, l4);
    cout << "Output: ";
    printList(result2);

    return 0;
}
