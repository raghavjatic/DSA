/*
 * Problem: Find Peak Element
 * Description: A peak element is an element that is strictly greater than its neighbors.
 * Given an integer array nums, find a peak element, and return its index.
 * You may imagine that nums[-1] = nums[n] = -∞.
 * Link: https://leetcode.com/problems/find-peak-element/
 *
 * Author: Raghav Jatic
 * Date: 28th January 2026
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        if(nums.size() == 1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[high] > nums[high-1]) return high;

        low=1;
        high--;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
                return mid;

            else if(nums[mid]<nums[mid+1])
                low=mid+1;

            else if(nums[mid]<nums[mid-1])
                high=mid-1;

            else
                low=mid+1;
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2,3,1};
    cout << sol.findPeakElement(nums1) << endl; // Expected: 2

    vector<int> nums2 = {1,2,1,3,5,6,4};
    cout << sol.findPeakElement(nums2) << endl; // Expected: 1 or 5

    return 0;
}
