/*
 * Problem: Split Array Largest Sum
 * Description: Given an integer array nums and an integer k, split nums into k non-empty
 * subarrays such that the largest sum of any subarray is minimized.
 * Return the minimized largest sum.
 * Link: https://leetcode.com/problems/split-array-largest-sum/
 *
 * Author: Raghav Jatic
 * Date: 31st January 2026
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int countSubarrays(vector<int>& nums, int mid)
    {
        int arr=1; //1st subarray
        long long sum = 0;
        for(int j=0;j<nums.size();j++)
        {
            if(sum + nums[j] <= mid)
                sum = sum+nums[j];

            else
            {
                arr +=1;
                sum=nums[j];
            }
        }
        return arr;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k) return -1;
        int low=nums[0];    //max element in arr
        int high=nums[0];   //sum of arr

        for(int i=1;i<n;i++)
        {
            if(low<nums[i])
                low= nums[i];

            high += nums[i];
        }

        while(low<=high)
        {
            int mid = low + (high - low) / 2;
            int a=countSubarrays(nums, mid);
            if(a > k)
                low=mid+1;

            else
                high=mid-1;
        }
        return low;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    cout << sol.splitArray(nums, k) << endl;
    // Expected output: 18

    return 0;
}
