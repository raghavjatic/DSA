/*
 * Problem: Remove Duplicates from Sorted List
 * Description: Given the head of a sorted linked list, delete all duplicates
 * such that each element appears only once. Return the linked list sorted as well.
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 *
 * Author: Raghav Jatic
 * Date: 26th December 2025
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next; // skip duplicate
            } else {
                curr = curr->next; // move forward
            }
        }
        return head;
    }
};

int main() {
    // Creating linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1,
                        new ListNode(1,
                        new ListNode(2,
                        new ListNode(3,
                        new ListNode(3)))));

    Solution sol;
    head = sol.deleteDuplicates(head);

    // Print result: Expected 1 -> 2 -> 3
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
