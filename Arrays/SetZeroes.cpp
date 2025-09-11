/**
 * Problem: Set Matrix Zeroes
 * Description: Given an m x n integer matrix, if an element is 0, 
 * set its entire row and column to 0. Do it in place.
 * Link: https://leetcode.com/problems/set-matrix-zeroes/
 * Author: Raghav Jatic
 * Date: 10th September 2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();        // number of rows
        int m = matrix[0].size();     // number of columns

        int col0=1;
        for(int i= 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    //mark the i-th row
                    matrix[i][0]=0;
                    //mark the j-th column
                    if(j!=0)
                    {
                        matrix[0][j]=0;
                    }
                    else
                    col0=0;

                }
            }
        }
        for(int i=1; i< n; i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j] != 0)
                //check for col and row
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0] == 0)
        {
            for(int j=0; j<m; j++)
            matrix[0][j]=0;
        }
        if(col0 == 0)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0]=0;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    sol.setZeroes(matrix);

    cout << "Matrix after setting zeroes:\n";
    for (auto &row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
