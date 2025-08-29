/*
 * Problem: Middle of the Linked List
 * Description: Given the head of a singly linked list, return the middle node of the linked list. 
 * If there are two middle nodes, return the second middle node.
 *
 * Link: https://leetcode.com/problems/middle-of-the-linked-list/
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
    ListNode* middleNode(ListNode* head) {
        ListNode* p = new ListNode;
        ListNode* q = new ListNode;
        p = q = head;
        while (q != NULL) {
            q = q->next;
            if (q != NULL) {
                p = p->next;
                q = q->next;
            }
        }
        return p;
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

    Solution sol;
    ListNode* mid = sol.middleNode(head);

    cout << "Middle Node and onwards: ";
    printList(mid);

    // Free memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
