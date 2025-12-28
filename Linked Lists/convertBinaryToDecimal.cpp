/*
 * Problem: Convert Binary Number in a Linked List to Integer
 * Description: Given a singly linked list where each node contains a binary digit,
 * return the decimal value of the number represented by the linked list.
 * Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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
    int getDecimalValue(ListNode* head) {
        int result = 0;

        while (head != NULL) {
            result = result * 2 + head->val;
            head = head->next;
        }

        return result;
    }
};

int main() {
    // Creating linked list: 1 -> 0 -> 1
    ListNode* head = new ListNode(1,
                        new ListNode(0,
                        new ListNode(1)));

    Solution sol;
    int result = sol.getDecimalValue(head);

    cout << result << endl;
    // Expected output: 5

    return 0;
}
