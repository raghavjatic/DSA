/*
 * Problem: Linked List Cycle
 * Description: Given the head of a linked list, determine if the linked list has a cycle in it.
 * A cycle exists if there is a node in the list that can be reached again by continuously following the next pointer.
 *
 * Link: https://leetcode.com/problems/linked-list-cycle/
 *
 * Author: Raghav Jatic
 * Date: 30th August 2025
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
    bool hasCycle(ListNode *head) {
        ListNode *p = new ListNode;
        ListNode *q = new ListNode;
        p = q = head;
        while (p != NULL && p->next != NULL) {
            p = p->next;
            p = p->next;
            q = q->next;
            if (p == q)
                return true;
        }
        return false;
    }
};

int main() {
    // Test 1: List without a cycle
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    Solution sol;
    cout << "Has Cycle (Test 1): " << (sol.hasCycle(head1) ? "true" : "false") << endl;

    // Free memory (no cycle, safe to delete)
    while (head1) {
        ListNode* temp = head1;
        head1 = head1->next;
        delete temp;
    }

    // Test 2: List with a cycle
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = head2->next; // cycle: node 4 points back to node 2

    cout << "Has Cycle (Test 2): " << (sol.hasCycle(head2) ? "true" : "false") << endl;

    // ⚠️ Do not delete nodes from head2 here because it has a cycle

    return 0;
}
