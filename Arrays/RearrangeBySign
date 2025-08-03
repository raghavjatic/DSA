/*
 * Problem: Rearrange Array Elements by Sign
 * Description: Given a 0-indexed integer array nums of even length, 
 * rearrange the elements such that every consecutive pair (nums[2i], nums[2i+1]) 
 * has nums[2i] > 0 and nums[2i+1] < 0. The relative order of positive and negative numbers should be preserved.
 * 
 * Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
 *
 * Author: Raghav Jatic
 * Date: 6th July 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int l = nums.size();
        vector<int> arr(l);
        int j = 0;
        int mid = l / 2;

        for (int i = 0; i < l; i++) {
            if (nums[i] < 0) {
                arr[mid++] = nums[i];
            } else if (nums[i] > 0) {
                arr[j++] = nums[i];
            }
        }

        j = 0;
        mid = l / 2;

        for (int i = 0; i < l; i++) {
            if (i % 2 == 0) {
                nums[i] = arr[j++];
            } else {
                nums[i] = arr[mid++];
            }
        }

        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> result = sol.rearrangeArray(nums);
    cout << "Rearranged Array: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
