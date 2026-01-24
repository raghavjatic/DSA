/*
 * Problem: Insert Interval
 * Description: You are given an array of non-overlapping intervals intervals where
 * intervals[i] = [starti, endi] represent the start and the end of the ith interval,
 * and intervals is sorted in ascending order by starti.
 * You are also given an interval newInterval = [start, end].
 * Insert newInterval into intervals such that intervals is still sorted and non-overlapping.
 * Link: https://leetcode.com/problems/insert-interval/
 *
 * Author: Raghav Jatic
 * Date: 24th January 2026
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n=intervals.size();
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0])
        {
            ans.push_back(intervals[i]);
            i=i+1;
        }

        while(i<n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0]=min(newInterval[0], intervals[i][0]);
            newInterval[1]=max(newInterval[1], intervals[i][1]);
            i=i+1;
        }

        ans.push_back(newInterval);

        while(i<n)
        {
            ans.push_back(intervals[i]);
            i=i+1;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};

    vector<vector<int>> result = sol.insert(intervals, newInterval);

    for (auto &in : result) {
        cout << "[" << in[0] << "," << in[1] << "] ";
    }
    cout << endl;
    // Expected output: [1,5] [6,9]

    return 0;
}
