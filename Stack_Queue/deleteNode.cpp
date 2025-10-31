/*
 * Problem: Delete Node in a Linked List
 * Description: Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 * Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
 *
 * Author: Raghav Jatic
 * Date: 1st November 2025
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {
    // Example: Linked list = 4 -> 5 -> 1 -> 9, delete node 5
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original list: ";
    for (ListNode* temp = head; temp; temp = temp->next)
        cout << temp->val << " ";
    cout << endl;

    Solution sol;
    sol.deleteNode(head->next); // delete node with value 5

    cout << "After deleting node 5: ";
    for (ListNode* temp = head; temp; temp = temp->next)
        cout << temp->val << " ";
    cout << endl;

    return 0;
}
