/*
 * Problem: Swap Nodes in Pairs
 * Description: Given a linked list, swap every two adjacent nodes and return its head.
 * You must solve the problem without modifying the values in the list's nodes.
 * Link: https://leetcode.com/problems/swap-nodes-in-pairs/
 *
 * Author: Raghav Jatic
 * Date: 27th December 2025
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;

        if(head->next->next == NULL)        //only 2 nodes
        {
            ListNode* temp=head;
            head=head->next;
            head->next=temp;
            temp->next=NULL;
        }   

        else if(head->next->next->next == NULL)  //only 3 nodes
        {
            ListNode* temp=head;
            head=head->next;
            temp->next=head->next;;
            head->next=temp;
        } 

        else
        {
            ListNode *p=head;
            head=head->next;
            p->next=head->next;;
            head->next=p;
            ListNode* q=p;
            p=p->next;

            while(p!=NULL && p->next!=NULL)
            {
                ListNode* temp=p;
                p=p->next;
                temp->next=p->next;;
                p->next=temp;
                q->next=p;
                q=temp;
                p=temp->next;
            }
        }  

        return head;
    }
};

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1,
                        new ListNode(2,
                        new ListNode(3,
                        new ListNode(4,
                        new ListNode(5)))));

    Solution sol;
    head = sol.swapPairs(head);

    // Print result
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    // Expected output (pairwise): 2 1 4 3 5

    return 0;
}
