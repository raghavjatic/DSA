/*
 * Problem: Binary Subarrays With Sum
 * Description: Given a binary array nums and an integer goal,
 * return the number of non-empty subarrays with a sum equal to goal.
 * Link: https://leetcode.com/problems/binary-subarrays-with-sum/
 *
 * Author: Raghav Jatic
 * Date: 14th February 2026
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal<0) return 0;

        int l=0,r=0;
        int n=nums.size();
        int sum=0;
        int ans=0;
        while(r<n)
        {
            sum+=nums[r];

            while(sum > goal)
            {
                sum=sum-nums[l];
                l=l+1;
            }
            ans= ans + (r-l+1);
            r= r+1;
        }

        int ans2= numSubarraysWithSum(nums,goal-1);
        return (ans-ans2);
        
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1,0,1,0,1};
    int goal = 2;

    cout << sol.numSubarraysWithSum(nums, goal) << endl;
    // Expected output: 4

    return 0;
}
