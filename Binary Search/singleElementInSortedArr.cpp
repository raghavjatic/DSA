/*
 * Problem: Single Element in a Sorted Array
 * Description: Given a sorted array consisting of only integers where every element
 * appears exactly twice, except for one element which appears exactly once.
 * Find this single element in O(log n) time and O(1) space.
 * Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
 *
 * Author: Raghav Jatic
 * Date: 28th January 2026
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Make mid even
            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1]) {
                // Pair is correct, go right
                low = mid + 2;
            } 
            else {
                // Pair is broken, go left
                high = mid;
            }
        }

        return nums[low];
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    cout << sol.singleNonDuplicate(nums) << endl;
    // Expected output: 2

    return 0;
}
