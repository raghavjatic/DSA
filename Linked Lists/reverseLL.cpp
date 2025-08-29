/*
 * Problem: Reverse Linked List
 * Description: Given the head of a singly linked list, reverse the list, and return its head.
 *
 * Link: https://leetcode.com/problems/reverse-linked-list/
 *
 * Author: Raghav Jatic
 * Date: 6th August 2025
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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = new ListNode;
        ListNode *q = new ListNode;
        ListNode *r = new ListNode;
        p = head;
        q = r = NULL;
        while (p != NULL) {
            q = r;
            r = p;
            p = p->next;
            r->next = q;
        }
        head = r;
        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    // Free memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
