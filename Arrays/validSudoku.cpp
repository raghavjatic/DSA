/*
 * Problem: Valid Sudoku
 * Description: Determine if a 9x9 Sudoku board is valid.
 * Only the filled cells need to be validated according to the rules of Sudoku.
 * Link: https://leetcode.com/problems/valid-sudoku/
 *
 * Author: Raghav Jatic
 * Date: 20th December 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> hash(10, 0);
        // checking rows
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.')
                    continue;
                int n = c - '0';
                if (hash[n] == 0) {
                    hash[n] += 1;
                } else {
                    return false;
                }
            }
            // initializing hash with zero
            for (int i = 0; i < 10; i++)
                hash[i] = 0;
        }

        // checking columns
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                char c = board[i][j];
                if (c == '.')
                    continue;
                int n = c - '0';
                if (hash[n] == 0) {
                    hash[n] += 1;
                } else {
                    return false;
                }
            }
            // initializing hash with zero
            for (int i = 0; i < 10; i++)
                hash[i] = 0;
        }

        // checking sub boxes
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                // initializing hash with zero
                for (int i = 0; i < 10; i++)
                    hash[i] = 0;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[boxRow + i][boxCol + j];
                        if (c == '.')
                            continue;

                        int n = c - '1';

                        if (hash[n] == 0) {
                            hash[n] += 1;
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << sol.isValidSudoku(board) << endl; // Expected: 1 (true)

    return 0;
}
