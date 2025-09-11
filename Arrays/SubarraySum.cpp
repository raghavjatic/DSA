/**
 * Problem: Subarray Sum Equals K
 * Description: Given an array of integers nums and an integer k, 
 * return the total number of subarrays whose sum equals to k.
 * Link: https://leetcode.com/problems/subarray-sum-equals-k/
 * Author: Raghav Jatic
 * Date: 11th September 2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //Using Hash map and prefix sum technique
        //two pointer method fails here because array may also have negative integers
        map<int , int> mpp;
        mpp[0]=1;
        int preSum=0;
        int cnt=0;
        for(int i =0; i< nums.size();i++)
        {
            preSum = preSum + nums[i];
            int remove = preSum - k;
            cnt = cnt + mpp[remove];
            mpp[preSum] += 1;
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 3;

    int result = sol.subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << " = " << result << endl;

    return 0;
}
