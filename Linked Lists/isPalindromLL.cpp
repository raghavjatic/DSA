/*
 * Problem: Palindrome Linked List
 * Description: Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
 *
 * Link: https://leetcode.com/problems/palindrome-linked-list/
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
    bool isPalindrome(ListNode* head) {
        ListNode *fast;
        ListNode *slow;
        fast=slow=head;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
                fast=fast->next;
            slow=slow->next;
        }
        // Reverse from middle
        ListNode *p = new ListNode;
        ListNode *q = new ListNode;
        ListNode *r = new ListNode;
        p= slow;
        q=r=NULL;
        while(p!=NULL)
        {
            q=r;
            r=p;
            p=p->next;
            r->next=q;
        }
        slow=r;

        fast=head;
        while(slow!=NULL)
        {
            if(fast->val == slow->val)
            {
                fast=fast->next;
                slow=slow->next;
            }
            else
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test 1: Palindrome [1,2,2,1]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(1);

    cout << "Is Palindrome (Test 1): " 
         << (sol.isPalindrome(head1) ? "true" : "false") << endl;

    // Test 2: Not Palindrome [1,2,3]
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);

    cout << "Is Palindrome (Test 2): " 
         << (sol.isPalindrome(head2) ? "true" : "false") << endl;

    return 0;
}
