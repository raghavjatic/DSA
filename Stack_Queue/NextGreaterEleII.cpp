/*
Problem: Next Greater Element II
Description:
Given a circular array nums (the next element of the last element is the first element),
return the Next Greater Number for every element. The Next Greater Number of a number x
is the first greater number to its traversing-order next in the array, which means you could
search circularly to find its next greater number. If it doesn't exist, output -1 for this number.
Link: https://leetcode.com/problems/next-greater-element-ii/
Author: Raghav Jatic
Date: 11th December 2025
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st; // store indices

        // iterate twice over the array (simulate circular)
        for (int i = 0; i < 2 * n; ++i) {
            int cur = nums[i % n];
            while (!st.empty() && nums[st.top()] < cur) {
                ans[st.top()] = cur;
                st.pop();
            }
            if (i < n) st.push(i); // only push indices from first pass
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 2, 1};
    vector<int> res1 = sol.nextGreaterElements(nums1);
    cout << "Input: [";
    for (size_t i=0;i<nums1.size();++i) {
        if (i) cout << ", ";
        cout << nums1[i];
    }
    cout << "]\nOutput: [";
    for (size_t i=0;i<res1.size();++i) {
        if (i) cout << ", ";
        cout << res1[i];
    }
    cout << "]\n\n";

    // Example 2 (additional)
    vector<int> nums2 = {5, 4, 3, 2, 1};
    vector<int> res2 = sol.nextGreaterElements(nums2);
    cout << "Input: [";
    for (size_t i=0;i<nums2.size();++i) {
        if (i) cout << ", ";
        cout << nums2[i];
    }
    cout << "]\nOutput: [";
    for (size_t i=0;i<res2.size();++i) {
        if (i) cout << ", ";
        cout << res2[i];
    }
    cout << "]\n";

    return 0;
}
