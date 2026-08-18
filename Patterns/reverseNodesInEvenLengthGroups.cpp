/*
============================================================
Problem: 2074. Reverse Nodes in Even Length Groups
Pattern type: Linked List - Reverse Linked List
Description: Given the head of a linked list, divide the nodes into groups
of increasing size starting from 1. Reverse only the groups
whose actual length is even and return the modified list.
LeetCode: https://leetcode.com/problems/reverse-nodes-in-even-length-groups/
Pattern : Reverse Linked List
Author: Raghav Jatic
Date: July 2026
============================================================
*/

#include <iostream>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Reverse exactly k nodes starting from head.
    // Returns the new head of the reversed group.
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (k--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Old head becomes the tail.
        head->next = curr;

        return prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        // Find length of the list.
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        int group = 1;
        int remaining = len;

        while (remaining > 0) {
            int actualSize = min(group, remaining);

            if (actualSize % 2 == 0) {
                // Connect previous group to new head after reversal.
                prev->next = reverse(curr, actualSize);

                // Current becomes the tail after reversal.
                prev = curr;
                curr = curr->next;
            } else {
                // Just move forward.
                for (int i = 0; i < actualSize; i++) {
                    prev = curr;
                    curr = curr->next;
                }
            }

            remaining -= actualSize;
            group++;
        }

        return dummy.next;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: [5,2,6,3,9,1,7,3,8,4]
    ListNode* head = new ListNode(
        5,
        new ListNode(
            2,
            new ListNode(
                6,
                new ListNode(
                    3,
                    new ListNode(
                        9,
                        new ListNode(
                            1,
                            new ListNode(
                                7,
                                new ListNode(
                                    3,
                                    new ListNode(
                                        8,
                                        new ListNode(4)
                                    )
                                )
                            )
                        )
                    )
                )
            )
        )
    );

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.reverseEvenLengthGroups(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}