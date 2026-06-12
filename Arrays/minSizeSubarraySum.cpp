/*
 * Problem: Minimum Size Subarray Sum
 * Description: Find the minimal length of a contiguous subarray
 *              of which the sum is greater than or equal to target.
 *              Return 0 if no such subarray exists.
 * Link: https://leetcode.com/problems/minimum-size-subarray-sum/
 * Author: Raghav Jatic
 * Date: 12th June 2026
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for(int right = 0; right < n; right++)
        {
            sum += nums[right];

            while(sum >= target)
            {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << "Minimum Length: "
         << sol.minSubArrayLen(target, nums)
         << endl;

    return 0;
}