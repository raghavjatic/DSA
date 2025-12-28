/*
 * Problem: Reverse Linked List II
 * Description: Given the head of a singly linked list and two integers left and right,
 * reverse the nodes of the list from position left to position right, and return the list.
 * Link: https://leetcode.com/problems/reverse-linked-list-ii/
 *
 * Author: Raghav Jatic
 * Date: 29th December 2025
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
    ListNode* reverse(ListNode* head, int n) {
        int cnt=0;
        ListNode *p = new ListNode;
        ListNode *q = new ListNode;
        ListNode *r = new ListNode;
        p= head;
        q=r=NULL;
        while(p!=NULL && cnt != n)
        {
            q=r;
            r=p;
            p=p->next;
            r->next=q;
            cnt=cnt+1;
        }
        head=r;
        return head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || head -> next == NULL)
            return head;

        if(left == right)
            return head;

        ListNode* a=head;    //a pointer for pointing on left position node
        ListNode* prev=NULL;

        ListNode dummy(0);
        dummy.next = head;
        if(left == 1)   // if reverse starts at head
        {
            prev = &dummy;
        }

        int c=1;
        while(a!=NULL && c < left)
        {
            prev = a;   //for pointing on node after which reversal takes place
            a= a->next;
            c = c+1;
        } 
        
        ListNode* nex = a;      //for pointing on the node before which reversal action takes place
        while(nex!=NULL && c <= right)
        {
            nex= nex->next;
            c = c+1;
        }

        prev->next = reverse(a , (right - left + 1));
        c=0;
        while(prev->next != NULL && c<= (right - left + 1))
        {
            prev=prev->next;
            c=c+1;         
        }
        prev-> next = nex;
        if(left == 1)
            return dummy.next;
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
    int left = 2;
    int right = 4;
    head = sol.reverseBetween(head, left, right);

    // Print result
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    // Expected output: 1 4 3 2 5

    return 0;
}


//expected solution:

// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         if (head == NULL || left == right)
//             return head;

//         ListNode dummy(0);
//         dummy.next = head;

//         ListNode* prev = &dummy;

//         // Move prev to node before left
//         for (int i = 1; i < left; i++) {
//             prev = prev->next;
//         }

//         // Reverse sublist
//         ListNode* curr = prev->next;
//         ListNode* next = NULL;

//         for (int i = 0; i < right - left; i++) {
//             next = curr->next;
//             curr->next = next->next;
//             next->next = prev->next;
//             prev->next = next;
//         }

//         return dummy.next;
//     }
// };
