/*
 * Problem: Continuous Subarray Sum
 * Description: Determine if the array contains a continuous subarray
 *              of size at least two whose sum is a multiple of k.
 * Link: https://leetcode.com/problems/continuous-subarray-sum/
 * Author: Raghav Jatic
 * Date: 17th June 2026
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // remainder 0 occurs before the array starts
        mp[0] = -1;

        int prefixSum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];

            int rem = prefixSum % k;

            if(mp.find(rem) != mp.end())
            {
                if(i - mp[rem] >= 2)
                    return true;
            }
            else
            {
                // store earliest occurrence only
                mp[rem] = i;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {23, 2, 4, 6, 7};
    int k1 = 6;

    vector<int> nums2 = {23, 2, 6, 4, 7};
    int k2 = 6;

    vector<int> nums3 = {23, 2, 6, 4, 7};
    int k3 = 13;

    cout << boolalpha;

    cout << "Output 1: "
         << sol.checkSubarraySum(nums1, k1)
         << endl;

    cout << "Output 2: "
         << sol.checkSubarraySum(nums2, k2)
         << endl;

    cout << "Output 3: "
         << sol.checkSubarraySum(nums3, k3)
         << endl;

    return 0;
}