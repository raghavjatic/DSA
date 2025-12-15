/*
 * Problem: Contains Duplicate
 * Description: Given an integer array nums, return true if any value appears at least twice in the array,
 * and return false if every element is distinct.
 * Link: https://leetcode.com/problems/contains-duplicate/
 *
 * Author: Raghav Jatic
 * Date: 16th December 2025
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            if(st.count(nums[i]))
            return true;
            st.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2,3,1};
    cout << sol.containsDuplicate(nums1) << endl; // Expected: 1 (true)

    vector<int> nums2 = {1,2,3,4};
    cout << sol.containsDuplicate(nums2) << endl; // Expected: 0 (false)

    vector<int> nums3 = {1,1,1,3,3,4,3,2,4,2};
    cout << sol.containsDuplicate(nums3) << endl; // Expected: 1 (true)

    return 0;
}
