/*
 * Problem: Reorder List
 * Description: Given the head of a singly linked list, reorder it to follow the pattern:
 * L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...
 * You may not modify the values in the list's nodes.
 * Link: https://leetcode.com/problems/reorder-list/
 *
 * Author: Raghav Jatic
 * Date: 2nd January 2026
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
    ListNode* reverse(ListNode* head) {
        ListNode* p = new ListNode;
        ListNode* q = new ListNode;
        ListNode* r = new ListNode;
        p = head;
        q = r = NULL;
        while (p != NULL) {
            q = r;
            r = p;
            p = p->next;
            r->next = q;
        }
        head = r;
        return head;
    }

    void reorderList(ListNode* head) {

        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;

        // finding middle of list
        ListNode* p = head;
        ListNode* q = head;
        ListNode* prev = NULL;
        while (p != NULL) {
            prev = q;
            p = p->next;
            if (p != NULL)
                p = p->next;
            q = q->next;
        }
        prev->next = NULL;

        // sorting the second half
        ListNode* head2 = q;
        head2 = reverse(head2);
        
        p = head;  // first half
        q = head2; // reversed second half

        while (p != NULL && q != NULL) {
            ListNode* a = p->next; // save next of first half
            ListNode* b = q->next; // save next of second half

            p->next = q; // link first → second
            if (a == NULL)
                break;   // avoid cycle at end
            q->next = a; // link second → next first

            p = a; // move pointers forward
            q = b;
        }

        return;
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
    sol.reorderList(head);

    // Print result
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    // Expected output: 1 5 2 4 3

    return 0;
}
