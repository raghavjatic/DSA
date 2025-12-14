/*
 * Problem: Search in Rotated Sorted Array
 * Description: Given an integer array nums sorted in ascending order (with distinct values),
 * and an integer target, return the index of target if it is in nums, or -1 if it is not.
 * Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
 *
 * Author: Raghav Jatic
 * Date: 15th December 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
       int l,r,mid;
       l=0;
       r=nums.size()-1;
       mid=(l+r)/2;
       while(l<=r)
       {
        
        mid=(l+r)/2;
        if(nums[mid]==target)
        return mid;


        if(nums[l]<=nums[mid])  //left half sorted
        {
             if (nums[l] <= target && target < nums[mid])
             r = mid - 1;
             else
             l = mid + 1;

        }
        else                    //right half sorted
        {
            if (nums[mid] < target && target <= nums[r])
            l = mid + 1;
            else
            r = mid - 1;
        }

       }

       return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4,5,6,7,0,1,2};
    cout << sol.search(nums1, 0) << endl; // Expected: 4

    vector<int> nums2 = {4,5,6,7,0,1,2};
    cout << sol.search(nums2, 3) << endl; // Expected: -1

    vector<int> nums3 = {1};
    cout << sol.search(nums3, 1) << endl; // Expected: 0

    return 0;
}
