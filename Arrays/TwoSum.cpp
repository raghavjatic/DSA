/*
 * Problem: Two Sum
 * Description: Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.
 * 
 * Link: https://leetcode.com/problems/two-sum/
 *
 * Author: Raghav Jatic
 * Date: 3rd July 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = 0;
        int sum = 0;
        vector<int> result = {0, 0};
        for (i = 0; i < (nums.size() - 1); i++) {
            for (j = i + 1; j < nums.size(); j++) {
                sum = nums[i] + nums[j];
                if (sum == target) {
                    result[0] = i;
                    result[1] = j;
                }
                sum = 0;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);
    cout << "Indices: ";
    for (int idx : result)
        cout << idx << " ";
    cout << endl;

    return 0;
}
