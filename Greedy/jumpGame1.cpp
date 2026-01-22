/*
 * Problem: Jump Game
 * Description: Given an array of non-negative integers nums, where nums[i] represents
 * the maximum jump length from index i, return true if you can reach the last index.
 * Link: https://leetcode.com/problems/jump-game/
 *
 * Author: Raghav Jatic
 * Date: 23rd January 2026
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        if (nums[0] == 0 && nums.size() == 1)
            return true;
        if (nums[0] == 0)
            return false;

        maxi = maxi + nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (i > maxi)
                return false;
            if (nums[i] == 0 && maxi < i)
                return false;
            if (maxi < nums[i] + i)
                maxi = max(maxi, i + nums[i]);
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2,3,1,1,4};
    cout << sol.canJump(nums1) << endl; // Expected: 1 (true)

    vector<int> nums2 = {3,2,1,0,4};
    cout << sol.canJump(nums2) << endl; // Expected: 0 (false)

    return 0;
}
