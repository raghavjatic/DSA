/*
 * Problem: Rotate List
 * Description: Given the head of a linked list, rotate the list to the right by k places.
 * Link: https://leetcode.com/problems/rotate-list/
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
    ListNode* rotate(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* p=head;
        ListNode* q=NULL;
        while(p != NULL && p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
        p->next = head;
        head=p;
        q->next=NULL;
        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;

        // Find length
        int len = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        // Reduce k
        k = k % len;
        if (k == 0)
            return head;

        for(int i=0;i<k;i++)
        {
            head = rotate(head);
        }
        return head;
    }
};

                    // Expected Solution:

// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if (head == NULL || head->next == NULL || k == 0)
//             return head;
//
//         // 1️⃣ Find length
//         int len = 1;
//         ListNode* tail = head;
//         while (tail->next != NULL) {
//             tail = tail->next;
//             len++;
//         }
//
//         // 2️⃣ Reduce k
//         k = k % len;
//         if (k == 0)
//             return head;
//
//         // 3️⃣ Make circular
//         tail->next = head;
//
//         // 4️⃣ Find new tail
//         int steps = len - k;
//         ListNode* newTail = head;
//         for (int i = 1; i < steps; i++) {
//             newTail = newTail->next;
//         }
//
//         // 5️⃣ Break circle
//         ListNode* newHead = newTail->next;
//         newTail->next = NULL;
//
//         return newHead;
//     }
// };

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1,
                        new ListNode(2,
                        new ListNode(3,
                        new ListNode(4,
                        new ListNode(5)))));

    Solution sol;
    int k = 2;
    head = sol.rotateRight(head, k);

    // Print result
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    // Expected output: 4 5 1 2 3

    return 0;
}
