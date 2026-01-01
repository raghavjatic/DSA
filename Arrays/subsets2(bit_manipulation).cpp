/*
 * Problem: Subsets II
 * Description: Given an integer array nums that may contain duplicates, return all
 * possible subsets (the power set). The solution set must not contain duplicate subsets.
 * Note: This problem is ideally solved using backtracking. This implementation uses
 * bit manipulation with a duplicate-check rule.
 * Link: https://leetcode.com/problems/subsets-ii/
 *
 * Author: Raghav Jatic
 * Date: 23rd December 2025
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// this problem must be done using backtracking and not bit manipulation as done here

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;   // 2^n subsets
        sort(nums.begin(),nums.end()); // sort the array to easily address duplicates

        vector<vector<int>> ans;

        for (int mask = 0; mask < total; mask++) {
            vector<int> subset;

            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    // duplicate rule
                    if (i > 0 && nums[i] == nums[i-1] && !(mask & (1 << (i-1)))) {
                        valid = false;
                        break;
                    }
                    subset.push_back(nums[i]);
                }
            }

            if (valid)
                ans.push_back(subset);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = sol.subsetsWithDup(nums);

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
