/*
 * Problem: Delete Node in a Linked List
 * Description: There is a singly-linked list node that is guaranteed not to be the tail node.
 * Given only access to that node, delete it from the linked list.
 *
 * Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        // can delete temp if you want to delete the node
        delete temp;
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
    // Creating list: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original List: ";
    printList(head);

    // Deleting node with value 5 (we pass pointer to node 5)
    Solution sol;
    sol.deleteNode(head->next);

    cout << "After Deletion: ";
    printList(head);

    // Free remaining nodes
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}