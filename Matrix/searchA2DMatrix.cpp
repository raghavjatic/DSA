/*
 * Problem: Search a 2D Matrix
 * Description: Write an efficient algorithm that searches for a value in an m x n matrix.
 * The matrix has the following properties:
 * 1) Integers in each row are sorted from left to right.
 * 2) The first integer of each row is greater than the last integer of the previous row.
 * Link: https://leetcode.com/problems/search-a-2d-matrix/
 *
 * Author: Raghav Jatic
 * Date: 30th December 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.empty() || matrix[0].empty())
            return false;

        int r = matrix.size();
        int c = matrix[0].size();

        //finding row in which we should search
        int row;
        int l=0;
        int h=r-1;
        int mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target)
                l=mid+1;
            else
                h=mid-1;
        }
        row = h;
        if (row < 0)
            return false;

        //finding element in columns of row found
        l=0;
        h=c-1;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] < target)
                l=mid+1;
            else
                h=mid-1;
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    cout << sol.searchMatrix(matrix, 3) << endl;   // Expected: 1 (true)
    cout << sol.searchMatrix(matrix, 13) << endl;  // Expected: 0 (false)

    return 0;
}
