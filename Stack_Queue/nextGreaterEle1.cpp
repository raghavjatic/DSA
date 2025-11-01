/*
 * Problem: Next Greater Element I
 * Description: For each element in nums1, find the next greater element in nums2. 
 * If it does not exist, return -1 for that number.
 * Link: https://leetcode.com/problems/next-greater-element-i/
 *
 * Author: Raghav Jatic
 * Date: 2nd November 2025
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1, len2;
        len1 = nums1.size();
        len2 = nums2.size();
        vector<int> ans(len1);
        vector<int> nge(len2);
        stack<int> st;

        for (int i = len2 - 1; i >= 0; i--) {
            while ((!st.empty()) && (st.top() <= nums2[i])) {
                st.pop();
            }
            if (st.empty()) {
                nge[i] = -1;
            } else
                nge[i] = st.top();
            st.push(nums2[i]);
        }

        int num;
        for (int i = 0; i < len1; i++) {
            num = nums1[i];
            for (int j = 0; j < len2; j++) {
                if (nums2[j] == num) {
                    ans[i] = nge[j];
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> res = sol.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int n : res) cout << n << " ";
    cout << endl;

    return 0;
}