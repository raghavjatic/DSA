/*
 * Problem: Summary Ranges
 * Description: Given a sorted integer array nums with no duplicates, return the summary of its ranges.
 * Link: https://leetcode.com/problems/summary-ranges/
 *
 * Author: Raghav Jatic
 * Date: 16th December 2025
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans(nums.size());
        int c=0;
        int start;
        start=0;
        for(int i=0;i<nums.size();i++)
        {
            if (i == nums.size() - 1 || nums[i] + 1 != nums[i + 1])
            {
                if(i==start)
                ans[c]=to_string(nums[i]);
                else
                ans[c]=to_string(nums[start])+"->"+to_string(nums[i]);
                c=c+1;
                start=i+1;
            }
        }
        ans.resize(c);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {0,1,2,4,5,7};
    vector<string> res1 = sol.summaryRanges(nums1);
    cout << "Ranges: ";
    for(auto &s : res1) cout << s << " ";
    cout << endl;

    vector<int> nums2 = {0,2,3,4,6,8,9};
    vector<string> res2 = sol.summaryRanges(nums2);
    cout << "Ranges: ";
    for(auto &s : res2) cout << s << " ";
    cout << endl;

    vector<int> nums3 = {};
    vector<string> res3 = sol.summaryRanges(nums3);
    cout << "Ranges: ";
    for(auto &s : res3) cout << s << " ";
    cout << endl;

    return 0;
}
