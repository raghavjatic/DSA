/*
 * Problem: Remove Nth Node From End of List
 * Description: Given the head of a linked list, remove the nth node from the end of the list and return its head.
 *
 * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fwd;
        ListNode *prev = new ListNode;
        ListNode *tail;
        tail = NULL;
        fwd = prev = head;

        if (head->next == NULL) {
            prev = head;
            head = NULL;
            delete prev;
            return head;
        }

        for (int i = 1; i <= n; i++) {
            fwd = fwd->next;
        }

        while (fwd != NULL) {
            tail = prev;
            prev = prev->next;
            fwd = fwd->next;
        }

        if (tail == NULL)
            head = head->next;
        else
            tail->next = prev->next;

        delete prev;
        return head;
    }
};

int main() {
    Solution sol;

    // Example 1: [1,2,3,4,5], n=2 → Output: [1,2,3,5]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    int n1 = 2;
    head1 = sol.removeNthFromEnd(head1, n1);

    cout << "List after removing " << n1 << "th node from end: ";
    for (ListNode* cur = head1; cur != nullptr; cur = cur->next) {
        cout << cur->val << " ";
    }
    cout << endl;

    // Example 2: [1], n=1 → Output: []
    ListNode* head2 = new ListNode(1);
    int n2 = 1;
    head2 = sol.removeNthFromEnd(head2, n2);

    cout << "List after removing " << n2 << "th node from end: ";
    for (ListNode* cur = head2; cur != nullptr; cur = cur->next) {
        cout << cur->val << " ";
    }
    cout << "(empty if nothing printed)" << endl;

    return 0;
}
