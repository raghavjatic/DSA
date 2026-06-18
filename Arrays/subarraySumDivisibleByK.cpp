/*
 * Problem: Subarray Sums Divisible by K
 * Description: Count the number of non-empty subarrays whose sum is divisible by k.
 * Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/
 * Author: Raghav Jatic
 * Date: June 2026
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        mp[0] = 1;

        int prefixSum = 0;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];

            int rem = prefixSum % k;

            // Handle negative remainders
            if(rem < 0)
                rem += k;

            ans += mp[rem];

            mp[rem]++;
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {4, 5, 0, -2, -3, 1};
    int k1 = 5;

    vector<int> nums2 = {5};
    int k2 = 9;

    cout << "Output 1: "
         << sol.subarraysDivByK(nums1, k1)
         << endl;

    cout << "Output 2: "
         << sol.subarraysDivByK(nums2, k2)
         << endl;

    return 0;
}