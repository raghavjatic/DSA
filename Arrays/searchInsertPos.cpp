#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Search Insert Position
Description: Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
Link: https://leetcode.com/problems/search-insert-position/
Author: Raghav Jatic
Date: 3rd November 2025
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return l;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << "Index: " << s.searchInsert(nums, target) << endl;  // Output: 2

    target = 2;
    cout << "Index: " << s.searchInsert(nums, target) << endl;  // Output: 1

    target = 7;
    cout << "Index: " << s.searchInsert(nums, target) << endl;  // Output: 4

    target = 0;
    cout << "Index: " << s.searchInsert(nums, target) << endl;  // Output: 0
}
