/*
 * Problem: Third Maximum Number
 * Description: Given an integer array nums, return the third distinct maximum number in this array.
 * If the third maximum does not exist, return the maximum number.
 * Link: https://leetcode.com/problems/third-maximum-number/
 *
 * Author: Raghav Jatic
 * Date: 12th December 2025
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    void sortDescending(std::vector<int>& nums) {
        // Sorts from beginning to end using the "greater than" logic
        std::sort(nums.begin(), nums.end(), std::greater<int>());
    }

    int thirdMax(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        sortDescending(nums);
        int c=0;
        int max=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>max)
            max=nums[i];
            c=c+1;
            if(c==3)
            return nums[i];
            while(i<nums.size()-1 && nums[i]==nums[i+1])
            {
                i=i+1;
            }
        }
        return max;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 2, 1};
    cout << sol.thirdMax(nums1) << endl; // Expected: 1

    vector<int> nums2 = {1, 2};
    cout << sol.thirdMax(nums2) << endl; // Expected: 2

    vector<int> nums3 = {2, 2, 3, 1};
    cout << sol.thirdMax(nums3) << endl; // Expected: 1

    vector<int> nums4 = {1, 1, 2};
    cout << sol.thirdMax(nums4) << endl; // Expected: 2

    return 0;
}
