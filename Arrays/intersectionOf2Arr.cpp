/*
 * Problem: Intersection of Two Arrays
 * Description: Given two integer arrays nums1 and nums2, return an array of their intersection.
 * Each element in the result must be unique and you may return the result in any order.
 * Link: https://leetcode.com/problems/intersection-of-two-arrays/
 *
 * Author: Raghav Jatic
 * Date: 12th December 2025
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        unordered_set<int> result;
        vector<int> ans;

        // store elements of first array
        for (int x : nums1) {
            s.insert(x);
        }

        // check elements of second array
        for (int x : nums2) {
            if (s.count(x) > 0) //if it is present in nums1(which we put in set)
             {
                result.insert(x);   // ensures uniqueness
            }
        }

        // convert set to vector
        for (int x : result) {
            ans.push_back(x);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};

    vector<int> res = sol.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    vector<int> nums3 = {4,9,5};
    vector<int> nums4 = {9,4,9,8,4};

    vector<int> res2 = sol.intersection(nums3, nums4);
    cout << "Intersection: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}
