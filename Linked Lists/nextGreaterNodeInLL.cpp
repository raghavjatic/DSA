/*
 * Problem: Next Greater Node In Linked List
 * Description: Given the head of a linked list, return an array of integers
 * where ans[i] is the value of the next greater node of the ith node (1-indexed).
 * If there is no next greater node, set ans[i] = 0.
 * Link: https://leetcode.com/problems/next-greater-node-in-linked-list/
 *
 * Author: Raghav Jatic
 * Date: 29th December 2025
 */

 // this is a monotonic stack problem just like next greater element in array

#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> nextLargerNodes(ListNode* head) {
         // Step 1: Convert linked list to array
        vector<int> vals;
        while (head != NULL) {
            vals.push_back(head->val);
            head = head->next;
        }

        int n = vals.size();
        vector<int> ans(n, 0);
        stack<int> st;   // stack stores values

        // Step 2: Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove elements smaller or equal to current
            while (!st.empty() && st.top() <= vals[i]) {
                st.pop();
            }

            // If stack not empty, top is next greater
            if (!st.empty()) {
                ans[i] = st.top();
            }

            // Push current value for left elements
            st.push(vals[i]);
        }

        return ans;
    }
};

int main() {
    // Creating linked list: 2 -> 1 -> 5
    ListNode* head = new ListNode(2,
                        new ListNode(1,
                        new ListNode(5)));

    Solution sol;
    vector<int> result = sol.nextLargerNodes(head);

    // Print result
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    // Expected output: 5 5 0

    return 0;
}
