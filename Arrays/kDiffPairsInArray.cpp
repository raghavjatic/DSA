/*
 * Problem: K-diff Pairs in an Array
 * Description: Return the number of unique k-diff pairs in the array,
 *              where the absolute difference between the two numbers is k.
 * Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/
 * Author: Raghav Jatic
 * Date: 10th June 2026
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        if (k < 0)
            return 0;

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = 1;
        int count = 0;
        int n = nums.size();

        while (right < n) {

            if (left == right) {
                right++;
                continue;
            }

            int diff = nums[right] - nums[left];

            if (diff < k) {
                right++;
            }
            else if (diff > k) {
                left++;
            }
            else {
                count++;

                left++;
                right++;

                // Skip duplicates
                while (right < n && nums[right] == nums[right - 1])
                    right++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 1, 4, 1, 5};
    int k1 = 2;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 1;

    vector<int> nums3 = {1, 3, 1, 5, 4};
    int k3 = 0;

    cout << "Output 1: " << sol.findPairs(nums1, k1) << endl;
    cout << "Output 2: " << sol.findPairs(nums2, k2) << endl;
    cout << "Output 3: " << sol.findPairs(nums3, k3) << endl;

    return 0;
}