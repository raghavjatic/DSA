/*
 * Problem: Merge Intervals
 * Description: Given an array of intervals where intervals[i] = [starti, endi],
 * merge all overlapping intervals and return an array of the non-overlapping intervals
 * that cover all the intervals in the input.
 * Link: https://leetcode.com/problems/merge-intervals/
 *
 * Author: Raghav Jatic
 * Date: 25th January 2026
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        int start = intervals[0][0];
        int end   = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++)
        {
            // Overlapping
            if(intervals[i][0] <= end)
            {
                end = max(end, intervals[i][1]);
            }
            // Not overlapping
            else
            {
                ans.push_back({start, end});
                start = intervals[i][0];
                end   = intervals[i][1];
            }
        }
        
        // Last interval
        ans.push_back({start, end});
        
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> result = sol.merge(intervals);

    for (auto &in : result) {
        cout << "[" << in[0] << "," << in[1] << "] ";
    }
    cout << endl;
    // Expected output: [1,6] [8,10] [15,18]

    return 0;
}
