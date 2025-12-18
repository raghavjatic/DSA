/*
 * Problem: Find All Numbers Disappeared in an Array
 * Description: Given an array nums of n integers where nums[i] is in the range [1, n],
 * return all the integers in the range [1, n] that do not appear in nums.
 * Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 *
 * Author: Raghav Jatic
 * Date: 18th December 2025
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> mp;
        vector<int> ans;

        for(int i=0;i<nums.size();i++)
            mp.insert(nums[i]);

        for(int i=1;i<=nums.size();i++)
        {
            if (!mp.count(i)) 
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4,3,2,7,8,2,3,1};
    vector<int> res1 = sol.findDisappearedNumbers(nums1);

    cout << "Disappeared Numbers: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {1,1};
    vector<int> res2 = sol.findDisappearedNumbers(nums2);

    cout << "Disappeared Numbers: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}
