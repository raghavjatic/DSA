/*
 * Problem: Excel Sheet Column Number
 * Description: Given a string columnTitle that represents the column title as appears in an Excel sheet,
 * return its corresponding column number.
 * Link: https://leetcode.com/problems/excel-sheet-column-number/
 *
 * Author: Raghav Jatic
 * Date: 19th December 2025
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;

        for (char c : columnTitle) {
            int value = (c - 'A') + 1;
            result = result * 26 + value;
        }

        return result;
    }
};

int main() {
    Solution sol;

    cout << sol.titleToNumber("A") << endl;    // Expected: 1
    cout << sol.titleToNumber("AB") << endl;   // Expected: 28
    cout << sol.titleToNumber("ZY") << endl;   // Expected: 701
    cout << sol.titleToNumber("FXSHRXW") << endl;

    return 0;
}
