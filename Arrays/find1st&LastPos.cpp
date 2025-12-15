/*
 * Problem: Find First and Last Position of Element in Sorted Array
 * Description: Given an array of integers nums sorted in non-decreasing order,
 * find the starting and ending position of a given target value.
 * If target is not found in the array, return [-1, -1].
 * Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 *
 * Author: Raghav Jatic
 * Date: 16th December 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result={-1,-1};
        int l,r,mid;
        l=0;
        r=nums.size()-1;
        mid=(l+r)/2;
        while(l<=r)
        {
            if(nums[mid]==target)
            {
                result[0]=mid;
                result[1]=mid;
                int a,b;
                a=b=mid;
                while(a - 1 >= 0 && nums[a - 1] == target)
                {
                    a=a-1;
                }
                while(b + 1 < nums.size() && nums[b + 1] == target)
                {
                    b=b+1;
                }
                result[0]=a;
                result[1]=b;
                return result;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
                mid=(l+r)/2;
            }
            else if(nums[mid]>target)
            {
                r=mid-1;
                mid=(l+r)/2;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {5,7,7,8,8,10};
    vector<int> res1 = sol.searchRange(nums1, 8);
    cout << "[" << res1[0] << ", " << res1[1] << "]" << endl; // Expected: [3,4]

    vector<int> nums2 = {5,7,7,8,8,10};
    vector<int> res2 = sol.searchRange(nums2, 6);
    cout << "[" << res2[0] << ", " << res2[1] << "]" << endl; // Expected: [-1,-1]

    vector<int> nums3 = {};
    vector<int> res3 = sol.searchRange(nums3, 0);
    cout << "[" << res3[0] << ", " << res3[1] << "]" << endl; // Expected: [-1,-1]

    return 0;
}
