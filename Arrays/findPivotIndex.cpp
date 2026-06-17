/*
 * Problem: Find Pivot Index
 * Description: Find the pivot index where the sum of all numbers
 *              strictly to the left equals the sum of all numbers
 *              strictly to the right.
 * Link: https://leetcode.com/problems/find-pivot-index/
 * Author: Raghav Jatic
 * Date: 17th June 2026
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int total = 0;

        for(int x : nums)
            total += x;

        int leftSum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            int rightSum = total - leftSum - nums[i];

            if(leftSum == rightSum)
                return i;

            leftSum += nums[i];
        }

        return -1;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    vector<int> nums2 = {1, 2, 3};
    vector<int> nums3 = {2, 1, -1};

    cout << "Output 1: "
         << sol.pivotIndex(nums1)
         << endl;

    cout << "Output 2: "
         << sol.pivotIndex(nums2)
         << endl;

    cout << "Output 3: "
         << sol.pivotIndex(nums3)
         << endl;

    return 0;
}