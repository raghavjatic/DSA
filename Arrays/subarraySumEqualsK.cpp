/*
 * Problem: Subarray Sum Equals K
 * Description: Count the total number of continuous subarrays
 *              whose sum equals k.
 * Link: https://leetcode.com/problems/subarray-sum-equals-k/
 * Author: Raghav Jatic
 * Date: June 2026
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);

        prefix[0] = nums[0];

        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int ans = 0;

        for(int start = 0; start < n; start++)
        {
            for(int end = start; end < n; end++)
            {
                int sum;

                if(start == 0)
                    sum = prefix[end];
                else
                    sum = prefix[end] - prefix[start - 1];

                if(sum == k)
                    ans++;
            }
        }

        return ans;
    }
};

/*
// Optimal Approach

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        mp[0] = 1;

        int currSum = 0;
        int ans = 0;

        for(int num : nums)
        {
            currSum += num;

            if(mp.find(currSum - k) != mp.end())
                ans += mp[currSum - k];

            mp[currSum]++;
        }

        return ans;
    }
};
*/

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;

    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;

    cout << "Output 1: "
         << sol.subarraySum(nums1, k1)
         << endl;

    cout << "Output 2: "
         << sol.subarraySum(nums2, k2)
         << endl;

    return 0;
}