/**
 * Problem: Pascal's Triangle
 * Description:
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * Each number is the sum of the two numbers directly above it.
 *
 * Link: https://leetcode.com/problems/pascals-triangle/
 *
 * Author: Raghav Jatic
 * Date: 9th April 2026
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        if(numRows >= 1) 
            ans.push_back({1});
        if(numRows >= 2) 
            ans.push_back({1,1});

        for(int i = 3; i <= numRows; i++) {
            vector<int> curr(i, 1);

            for(int j = 1; j < i - 1; j++) {
                curr[j] = ans[i-2][j-1] + ans[i-2][j];
            }

            ans.push_back(curr);
        }

        return ans;
    }
};

int main() {
    Solution obj;
    int numRows = 5;

    vector<vector<int>> result = obj.generate(numRows);

    for(const auto& row : result) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}