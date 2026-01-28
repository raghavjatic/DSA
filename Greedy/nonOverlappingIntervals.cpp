/*
 * Problem: Non-overlapping Intervals
 * Description: Given an array of intervals intervals where intervals[i] = [starti, endi],
 * return the minimum number of intervals you need to remove to make the rest of the intervals
 * non-overlapping.
 * Link: https://leetcode.com/problems/non-overlapping-intervals/
 *
 * Author: Raghav Jatic
 * Date: 26th January 2026
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n == 0) return 0;
        sort(intervals.begin(),intervals.end());
        int c=0;
        int end=intervals[0][1];
        for(int i = 1; i < n; i++)
        {
            // Overlap
            if(intervals[i][0] < end)
            {
                c++;
                
                // Keep the smaller ending interval
                end = min(end, intervals[i][1]);
            }
            // No overlap
            else
            {
                end = intervals[i][1];
            }
        }
        return c;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};

    cout << sol.eraseOverlapIntervals(intervals) << endl;
    // Expected output: 1

    return 0;
}
