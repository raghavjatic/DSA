/*
 * Problem: Subsets
 * Description: Given an integer array nums, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets.
 * Link: https://leetcode.com/problems/subsets/
 *
 * Author: Raghav Jatic
 * Date: 30th December 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;   // 2^n subsets

        vector<vector<int>> ans;

        for (int mask = 0; mask < total; mask++) {
            vector<int> subset;

            for (int i = 0; i < n; i++) {
                // check if i-th bit is set
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);

    // Print all subsets
    for (auto &subset : result) {
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
