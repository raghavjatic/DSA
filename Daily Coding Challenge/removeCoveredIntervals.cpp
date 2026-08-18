/*
============================================================
Problem: 1288. Remove Covered Intervals
Pattern type: Intervals
Description:
Given a list of intervals, remove all intervals that are covered
by another interval and return the number of remaining intervals.
LeetCode: https://leetcode.com/problems/remove-covered-intervals/
Author: Raghav Jatic
Date: 7th July 2026
============================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        // Keep only the interval with the largest end
        // for every starting point.
        vector<vector<int>> temp;

        int n = intervals.size();

        for (int i = 0; i < n; ) {
            int j = i;

            while (j + 1 < n && intervals[j + 1][0] == intervals[i][0])
                j++;

            // intervals[j] has the largest end for this start
            temp.push_back(intervals[j]);

            i = j + 1;
        }

        int ans = temp.size();
        int maxEnd = temp[0][1];

        for (int i = 1; i < temp.size(); i++) {
            if (temp[i][1] <= maxEnd) {
                ans--;
            } else {
                maxEnd = temp[i][1];
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> intervals = {
        {1, 4},
        {3, 6},
        {2, 8}
    };

    cout << "Remaining intervals: "
         << obj.removeCoveredIntervals(intervals) << endl;

    return 0;
}