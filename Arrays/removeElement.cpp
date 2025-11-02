/*
 * Problem: Remove Element
 * Description: Removes all occurrences of a given value in-place and returns the new length.
 * Elements beyond the new length can be ignored.
 * Link: https://leetcode.com/problems/remove-element/
 *
 * Author: Raghav Jatic
 * Date: 1st November 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int temp;
        int k = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k = k + 1;
            }
        }
        return k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int newLen = sol.removeElement(nums, val);

    cout << "After removing " << val << ": ";
    for (int i = 0; i < newLen; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}