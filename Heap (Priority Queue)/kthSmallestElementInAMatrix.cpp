/**
 * Problem: Kth Smallest Element in a Sorted Matrix
 * Description: Given an n x n matrix where each of the rows and columns is sorted in ascending order,
 * return the kth smallest element in the matrix.
 * Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 * Author: Raghav Jatic
 * Date: 23rd March 2026
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        // {value, {row, col}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        // push first column
        for(int i = 0; i < n; i++) {
            pq.push({matrix[i][0], {i, 0}});
        }

        int ans = 0;

        while(k--) {
            auto top = pq.top();
            pq.pop();

            int val = top.first;
            int i = top.second.first;
            int j = top.second.second;

            ans = val;

            // move right
            if(j + 1 < n) {
                pq.push({matrix[i][j+1], {i, j+1}});
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    int k = 8;

    int result = obj.kthSmallest(matrix, k);

    cout << "Kth Smallest Element: " << result << endl;

    return 0;
}