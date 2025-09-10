/*
 * Problem: Intersection of Two Linked Lists
 * Description: Given the heads of two singly linked-lists headA and headB, 
 * return the node at which the two lists intersect. If the two linked lists 
 * have no intersection, return null.
 *
 * Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
 *
 * Author: Raghav Jatic
 * Date: 6th August 2025
 */

#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        stack<ListNode*> st1;
        stack<ListNode*> st2;
        ListNode *p = headA;
        ListNode *q = headB;
        ListNode *a = nullptr;

        // Push all nodes into stacks
        while (p != NULL || q != NULL) {
            if (p != NULL) {
                st1.push(p);
                p = p->next;
            }
            if (q != NULL) {
                st2.push(q);
                q = q->next;
            }
        }

        // Pop while tops are equal
        while (!st1.empty() && !st2.empty() && st1.top() == st2.top()) {
            a = st1.top(); // update last common node
            st1.pop();
            st2.pop();
        }

        return a;
    }
};

// Helper function to print linked list from a given node
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

    // Create two linked lists with intersection
    // List A: 1 -> 9 -> 1 \
    //                        -> 2 -> 4
    // List B:       3 -----/
    ListNode* intersect = new ListNode(2);
    intersect->next = new ListNode(4);

    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(9);
    headA->next->next = new ListNode(1);
    headA->next->next->next = intersect;

    ListNode* headB = new ListNode(3);
    headB->next = intersect;

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    ListNode* result = sol.getIntersectionNode(headA, headB);
    if (result) {
        cout << "Intersection at node with value: " << result->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
