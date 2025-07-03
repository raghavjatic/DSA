/*
 * Problem: Majority Element
 * Description: Given an array `nums` of size n, return the majority element. 
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * 
 * Link: https://leetcode.com/problems/majority-element/
 *
 * Author: Raghav Jatic
 * Date: 3rd July 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int meindex = 0;

        for (int i = 0; i <= nums.size() / 2; i++) {
            count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j])
                    count++;
                if (count > nums.size() / 2) {
                    meindex = i;
                    break;
                }
            }
            if (count > nums.size() / 2) {
                meindex = i;
                break;
            }
        }
        return nums[meindex];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int result = sol.majorityElement(nums);
    cout << "Majority Element: " << result << endl;

    return 0;
}
