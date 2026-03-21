/**
 * Problem: Find All Duplicates in an Array
 * Description: Given an integer array nums of length n where all the integers are in the range [1, n],
 * some elements appear twice and others appear once. Return an array of all the integers that appear twice.
 * Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * Author: Raghav Jatic
 * Date: 22nd March 2026
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<int> ans;

//         for(int i=0;i< nums.size() -1 ;i++)
//         {
//             if(nums[i] == nums[i+1])
//             {
//                 ans.push_back(nums[i]);
//                 i=i+1;            
//             }
//         }
//         return ans;
//     }
// };

//alternate soln

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;

            if (nums[idx] < 0) {
                ans.push_back(abs(nums[i]));
            } else {
                nums[idx] = -nums[idx];
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {4,3,2,7,8,2,3,1};

    vector<int> result = obj.findDuplicates(nums);

    cout << "Duplicates: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}