/**
 * Problem: Rotate Image
 * Description: You are given an n x n 2D matrix representing an image, 
 * rotate the image by 90 degrees (clockwise).
 * Link: https://leetcode.com/problems/rotate-image/
 * Author: Raghav Jatic
 * Date: 10th September 2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // TRANSPOSE AND THEN REVERSE THE MATRIX
        int n=matrix.size();

        //Transposing
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1; j<n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //Reversing
        for(int i=0;i<n;i++)
        {
            //row is matrix[i]
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    sol.rotate(matrix);

    cout << "Rotated Matrix:\n";
    for (auto &row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
