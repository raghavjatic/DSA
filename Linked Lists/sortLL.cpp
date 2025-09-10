/*
 * Problem: Sort List
 * Description: Sorts a linked list in O(n log n) time and constant space complexity using merge sort.
 *
 * Link: https://leetcode.com/problems/sort-list/
 *
 * Author: Raghav Jatic
 * Date: 2nd September 2025
 */

/**
 * Definition for singly-linked list.
 * */
  struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
#include <iostream>
using namespace std;

class Solution {
public:
    // Merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;   // if first list empty, return second
        if (!l2) return l1;   // if second list empty, return first

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = (l1 ? l1 : l2);
        return dummy.next;
    }

    // Find middle node
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // fast starts ahead to split properly

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Sort list using merge sort
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; // single node or empty LL

        // 1. Split list into halves
        ListNode* mid = getMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;

        // 2. Sort each half
        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(right);

        // 3. Merge sorted halves
        return merge(leftSorted, rightSorted);
    }
};

// Example main() to test
int main() {
    // Creating unsorted linked list: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution sol;
    ListNode* sorted = sol.sortList(head);

    cout << "Sorted List: ";
    while (sorted) {
        cout << sorted->val << " ";
        sorted = sorted->next;
    }
    cout << endl;

    return 0;
}
