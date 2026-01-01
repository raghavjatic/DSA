/*
 * Problem: Search in Rotated Sorted Array II
 * Description: Given a rotated sorted array that may contain duplicates,
 * determine if a given target exists in the array.
 * Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 *
 * Author: Raghav Jatic
 * Date: 31st December 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;

        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return true;

            // Case 1: duplicates block decision
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l++;
                r--;
                continue;
            }

            // Left half sorted
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            // Right half sorted
            else {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2,5,6,0,0,1,2};

    cout << sol.search(nums, 0) << endl; // Expected: 1 (true)
    cout << sol.search(nums, 3) << endl; // Expected: 0 (false)

    return 0;
}
