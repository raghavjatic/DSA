/*
 * Problem: Remove Linked List Elements
 * Description: Given the head of a linked list and an integer val, remove all the
 * nodes of the linked list that have Node.val == val, and return the new head.
 * Link: https://leetcode.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head && head->val == val)
        {
            head=head->next;
        }

        ListNode* p=head;
        while(p!=NULL && p->next != NULL)
        {
            if(p->next->val == val)
            {
                p->next=p->next->next;
            }
            else
                p=p->next;
        }
        return head;
    }
};

int main() {
    // Creating linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1,
                        new ListNode(2,
                        new ListNode(6,
                        new ListNode(3,
                        new ListNode(4,
                        new ListNode(5,
                        new ListNode(6)))))));

    Solution sol;
    int val = 6;
    head = sol.removeElements(head, val);

    // Print result: Expected 1 -> 2 -> 3 -> 4 -> 5
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
