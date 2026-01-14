/*
 * Problem: Range Sum Query - Immutable
 * Description: Given an integer array nums, handle multiple queries of the form
 * sumRange(left, right), which returns the sum of the elements between indices
 * left and right inclusive.
 * Link: https://leetcode.com/problems/range-sum-query-immutable/
 *
 * Author: Raghav Jatic
 * Date: 13th January 2026
 */

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> p;

    NumArray(vector<int>& nums) {
        p.resize(nums.size()+1 , 0);
        for(int i=0;i<nums.size();i++)
        {
            p[i + 1] = p[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return p[right + 1] - p[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    NumArray* obj = new NumArray(nums);

    cout << obj->sumRange(0, 2) << endl; // Expected: 1
    cout << obj->sumRange(2, 5) << endl; // Expected: -1
    cout << obj->sumRange(0, 5) << endl; // Expected: -3

    return 0;
}
