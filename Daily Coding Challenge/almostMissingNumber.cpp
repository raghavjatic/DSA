/*
============================================================
Problem: 3471. Find the Largest Almost Missing Integer
Pattern type: Sliding Pointer
Description:
Given an array nums and an integer k, find the largest integer
that appears in exactly one subarray of length k.
Return -1 if no such integer exists.
LeetCode: https://leetcode.com/problems/find-the-largest-almost-missing-integer/
Author: Raghav Jatic
Date: 19th August 2026
============================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();
        int ans = -1;

        for(int num = 0; num <= 50; num++)
        {
            int count = 0;

            for(int i = 0; i <= n-k; i++)
            {
                bool found = false;

                for(int j = i; j < i+k; j++)
                {
                    if(nums[j] == num)
                    {
                        found = true;
                        break;
                    }
                }

                if(found)
                    count++;
            }

            if(count == 1)
                ans = max(ans, num);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 9, 2, 3, 3};
    int k = 3;

    cout << "Input: nums = {3, 9, 2, 3, 3}, k = " << k << endl;
    cout << "Output: " << obj.largestInteger(nums, k) << endl;

    return 0;
}