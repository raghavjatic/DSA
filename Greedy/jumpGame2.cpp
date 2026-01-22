/*
 * Problem: Jump Game II
 * Description: Given an array of non-negative integers nums, where nums[i] represents
 * the maximum jump length from index i, return the minimum number of jumps to reach
 * the last index.
 * Link: https://leetcode.com/problems/jump-game-ii/
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
    int jump(vector<int>& nums) {
        int jumps=0;
        int l = 0;
        int r=0;
        while(r< nums.size()-1)
        {
            int farthest = 0;
            for(int i = l; i <= r; i++)
            {
                farthest = max(farthest , nums[i]+i);
            }
            l=r+1;
            r=farthest;
            jumps=jumps+1;
        }
        return jumps;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2,3,1,1,4};
    cout << sol.jump(nums1) << endl; // Expected: 2

    vector<int> nums2 = {2,3,0,1,4};
    cout << sol.jump(nums2) << endl; // Expected: 2

    return 0;
}
