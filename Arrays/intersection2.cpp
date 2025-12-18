/*
 * Problem: Intersection of Two Arrays II
 * Description: Given two integer arrays nums1 and nums2, return an array of their intersection.
 * Each element in the result should appear as many times as it shows in both arrays.
 * Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/
 *
 * Author: Raghav Jatic
 * Date: 18th December 2025
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        unordered_map<int, int> result;
        vector<int> ans;

        for (int x : nums1) {
            mp[x]++; // increments frequency of x
        }

        for (int i = 0; i < nums2.size(); i++) {
            if (mp.find(nums2[i]) != mp.end()) {
                result[nums2[i]]++;
                mp[nums2[i]]--;
                if (mp[nums2[i]] == 0) {
                    mp.erase(nums2[i]);
                }
            }
        }
        for (auto it : result) {
            int value = it.first; // the number itself
            int freq = it.second; // how many times it appears

            // push 'value' into ans 'freq' times
            while (freq > 0) {
                ans.push_back(value);
                freq--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};

    vector<int> res1 = sol.intersect(nums1, nums2);
    cout << "Intersection: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    vector<int> nums3 = {4,9,5};
    vector<int> nums4 = {9,4,9,8,4};

    vector<int> res2 = sol.intersect(nums3, nums4);
    cout << "Intersection: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}
