/*
 * Problem: 3Sum
 * Description: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * Notice that the solution set must not contain duplicate triplets.
 * Link: https://leetcode.com/problems/3sum/
 *
 * Author: Raghav Jatic
 * Date: 20th January 2026
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i
            if (nums[i] > 0) break; // no possible triplet beyond this

            int l = i + 1, r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1]) l++; // skip dup l
                    while (l < r && nums[r] == nums[r + 1]) r--; // skip dup r
                }
                else if (sum < 0) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);

    for (auto &triplet : result) {
        cout << "[ ";
        for (int x : triplet) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
