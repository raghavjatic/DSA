/*
 * Problem: Linked List Cycle II
 * Description: Given the head of a linked list, return the node where the cycle begins. 
 * If there is no cycle, return null. 
 * Do not modify the linked list.
 *
 * Link: https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode* detectCycle(ListNode* head) {
        ListNode* p = new ListNode;
        ListNode* t = new ListNode;
        p = t = head;
        while (p != NULL && p->next != NULL) {
            p = p->next->next;
            t = t->next;
            if (p == t) {
                p = head;
                while (p != t) {
                    p = p->next;
                    t = t->next;
                }
                return p;
            }
        }
        return NULL;
    }
};

int main() {
    Solution sol;

    // Test 1: No cycle
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    ListNode* cycleNode1 = sol.detectCycle(head1);
    cout << "Cycle starts at (Test 1): " 
         << (cycleNode1 ? to_string(cycleNode1->val) : "NULL") << endl;

    // Free memory (safe since no cycle)
    while (head1) {
        ListNode* temp = head1;
        head1 = head1->next;
        delete temp;
    }

    // Test 2: With cycle
    ListNode* head2 = new ListNode(3);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(0);
    head2->next->next->next = new ListNode(-4);
    head2->next->next->next->next = head2->next; // cycle at node with val=2

    ListNode* cycleNode2 = sol.detectCycle(head2);
    cout << "Cycle starts at (Test 2): " 
         << (cycleNode2 ? to_string(cycleNode2->val) : "NULL") << endl;

    //  Not freeing memory for head2 due to cycle

    return 0;
}
