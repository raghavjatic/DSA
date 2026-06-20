/*
 * Problem: Longest Consecutive Sequence
 * Description: Find the length of the longest consecutive elements sequence.
 * Link: https://leetcode.com/problems/longest-consecutive-sequence/
 * Author: Raghav Jatic
 * Date: 19th June 2026
 * Pattern type: Hash Set
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for(int num : st)
        {
            if(st.find(num - 1) == st.end())
            {
                int currNum = num;
                int currLen = 1;

                while(st.find(currNum + 1) != st.end())
                {
                    currNum++;
                    currLen++;
                }

                ans = max(ans, currLen);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

    cout << "Output 1: "
         << sol.longestConsecutive(nums1)
         << endl;

    cout << "Output 2: "
         << sol.longestConsecutive(nums2)
         << endl;

    return 0;
}