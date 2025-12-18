/*
 * Problem: Excel Sheet Column Title
 * Description: Given an integer columnNumber, return its corresponding column title
 * as it appears in an Excel sheet.
 * Link: https://leetcode.com/problems/excel-sheet-column-title/
 *
 * Author: Raghav Jatic
 * Date: 19th December 2025
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while (columnNumber > 0) {
            columnNumber--;  // key step
            char c = 'A' + (columnNumber % 26);
            ans.push_back(c);
            columnNumber /= 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    cout << sol.convertToTitle(1) << endl;    // Expected: A
    cout << sol.convertToTitle(28) << endl;   // Expected: AB
    cout << sol.convertToTitle(701) << endl;  // Expected: ZY
    cout << sol.convertToTitle(2147483647) << endl;

    return 0;
}
