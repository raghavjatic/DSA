/*
 * Problem: Contains Duplicate II
 * Description: Given an integer array nums and an integer k, return true if there are two distinct indices i and j
 * such that nums[i] == nums[j] and abs(i - j) <= k.
 * Link: https://leetcode.com/problems/contains-duplicate-ii/
 *
 * Author: Raghav Jatic
 * Date: 16th December 2025
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < nums.size(); i++) {
            // If number already seen before
            if (lastIndex.find(nums[i]) != lastIndex.end()) {
                // Check distance
                if (i - lastIndex[nums[i]] <= k) {
                    return true;
                }
            }
            // Update last seen index
            lastIndex[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2,3,1};
    cout << sol.containsNearbyDuplicate(nums1, 3) << endl; // Expected: 1 (true)

    vector<int> nums2 = {1,0,1,1};
    cout << sol.containsNearbyDuplicate(nums2, 1) << endl; // Expected: 1 (true)

    vector<int> nums3 = {1,2,3,1,2,3};
    cout << sol.containsNearbyDuplicate(nums3, 2) << endl; // Expected: 0 (false)

    return 0;
}
