/*
 * Problem: Maximum Subarray
 * Description: Given an integer array nums, find the contiguous subarray 
 * (containing at least one number) which has the largest sum and return its sum.
 * 
 * Link: https://leetcode.com/problems/maximum-subarray/
 *
 * Author: Raghav Jatic
 * Date: 3rd July 2025
 */

#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > maxi) {
                maxi = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = sol.maxSubArray(nums);
    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}
