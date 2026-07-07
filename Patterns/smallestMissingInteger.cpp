/*
 * Problem: Smallest Missing Integer Greater Than Sequential Prefix Sum
 * Description: Find the sum of the longest sequential prefix, then return the
 *              smallest integer greater than or equal to that sum that is not
 *              present in the array.
 * Link: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/
 * Author: Raghav Jatic
 * Date: 2nd July 2026
 * Pattern type: String Manipulation
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        sum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        sort(nums.begin(), nums.end());

        int ans = sum;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < ans)
                continue;

            if (nums[i] == ans)
                ans++;
            else
                break;
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 2, 5};
    vector<int> nums2 = {3, 4, 5, 1, 12, 14, 13};

    cout << "Output 1: "
         << sol.missingInteger(nums1)
         << endl;

    cout << "Output 2: "
         << sol.missingInteger(nums2)
         << endl;

    return 0;
}