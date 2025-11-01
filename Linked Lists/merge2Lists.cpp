/*
 * Problem: Merge Two Sorted Lists
 * Description: Merges two sorted linked lists and returns the head of the new sorted list.
 * The new list should be made by splicing together the nodes of the first two lists.
 * Link: https://leetcode.com/problems/merge-two-sorted-lists/
 *
 * Author: Raghav Jatic
 * Date: 1stNovember 2025
 */

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head;          // temporary head
        ListNode* tail = &head; // pointer to the end of merged list
        head.next = NULL;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes
        if (list1 != NULL)
            tail->next = list1;
        else
            tail->next = list2;

        return head.next; // return actual head
    }
};

int main() {
    // Example test
    ListNode* a = new ListNode(1, new ListNode(3, new ListNode(5)));
    ListNode* b = new ListNode(2, new ListNode(4, new ListNode(6)));

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(a, b);

    cout << "Merged List: ";
    while (merged) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;

    return 0;
}
