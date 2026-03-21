/**
 * Problem: Kth Largest Element in an Array
 * Description: Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
 * Author: Raghav Jatic
 * Date: 21st March 2026
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i=0;i<nums.size();i++)
        {
            heap.push(nums[i]);
            if(heap.size()>k)
            heap.pop();
        }
        return heap.top();
    }
};

int main() {
    Solution obj;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    int result = obj.findKthLargest(nums, k);

    cout << "Kth Largest Element: " << result << endl;

    return 0;
}