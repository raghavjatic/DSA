/*
 * Problem: Odd Even Linked List
 * Description: Given the head of a singly linked list, group all the nodes with odd indices together 
 * followed by the nodes with even indices, and return the reordered list.
 * The first node is considered odd, and the second node is even, and so on.
 *
 * Link: https://leetcode.com/problems/odd-even-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;   // link odd to next odd
            odd = odd->next;          // move odd forward

            even->next = odd->next;   // link even to next even
            even = even->next;        // move even forward
        }

        odd->next = evenHead; // attach even list after odd list
        return head;
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

    // Example 1: Input: 1 -> 2 -> 3 -> 4 -> 5
    // Output: 1 -> 3 -> 5 -> 2 -> 4
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);

    cout << "Input: ";
    printList(l1);

    ListNode* result = sol.oddEvenList(l1);
    cout << "Output: ";
    printList(result);

    // Example 2: Input: 2 -> 1 -> 3 -> 5 -> 6 -> 4 -> 7
    // Output: 2 -> 3 -> 6 -> 7 -> 1 -> 5 -> 4
    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(1);
    l2->next->next = new ListNode(3);
    l2->next->next->next = new ListNode(5);
    l2->next->next->next->next = new ListNode(6);
    l2->next->next->next->next->next = new ListNode(4);
    l2->next->next->next->next->next->next = new ListNode(7);

    cout << "\nInput: ";
    printList(l2);

    ListNode* result2 = sol.oddEvenList(l2);
    cout << "Output: ";
    printList(result2);

    return 0;
}
