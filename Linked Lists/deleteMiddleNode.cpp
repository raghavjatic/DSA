/*
 * Problem: Delete the Middle Node of a Linked List
 * Description: Given the head of a linked list, delete the middle node and return the head.
 * If the list has an even number of nodes, delete the second middle node.
 *
 * Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *fast;
        ListNode *slow;
        ListNode *tail;
        fast = slow = head;

        if (head->next == NULL)
            return NULL;

        if (head->next->next == NULL) {
            head->next = NULL;
            return head;
        }

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            tail = slow;
            slow = slow->next;
        }

        tail->next = slow->next;
        delete slow;
        return head;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example 1: [1,3,4,7,1,2,6] → [1,3,4,1,2,6]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(4);
    head1->next->next->next = new ListNode(7);
    head1->next->next->next->next = new ListNode(1);
    head1->next->next->next->next->next = new ListNode(2);
    head1->next->next->next->next->next->next = new ListNode(6);

    cout << "Original list: ";
    printList(head1);
    head1 = sol.deleteMiddle(head1);
    cout << "After deleting middle: ";
    printList(head1);

    // Example 2: [1,2] → [1]
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    cout << "Original list: ";
    printList(head2);
    head2 = sol.deleteMiddle(head2);
    cout << "After deleting middle: ";
    printList(head2);

    // Example 3: [1] → []
    ListNode* head3 = new ListNode(1);

    cout << "Original list: ";
    printList(head3);
    head3 = sol.deleteMiddle(head3);
    cout << "After deleting middle: ";
    printList(head3); // should print nothing

    return 0;
}
