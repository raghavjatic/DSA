/*
 * Problem: Add Strings
 * Description: Given two non-negative integers num1 and num2 represented as strings,
 * return the sum of num1 and num2 as a string.
 * Link: https://leetcode.com/problems/add-strings/
 *
 * Author: Raghav Jatic
 * Date: 21st December 2025
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int j,k;
        j=num1.size()-1;
        k=num2.size()-1;
        int carry=0;;
        string sum="";
        while (j >= 0 && k >= 0) {
            int val = (num1[j] - '0') + (num2[k] - '0') + carry;
            carry = val / 10;
            val = val % 10;

            sum.push_back(val + '0');

            j = j - 1;
            k = k - 1;
        }

        while (j >= 0) {
            int val = (num1[j] - '0') + carry;
            carry = val / 10;
            val = val % 10;

            sum.push_back(val + '0');
            j = j - 1;
        }

        while (k >= 0) {
            int val = (num2[k] - '0') + carry;
            carry = val / 10;
            val = val % 10;

            sum.push_back(val + '0');
            k = k - 1;
        }

        if (carry == 1)
            sum.push_back('1');

        reverse(sum.begin(), sum.end());
        return sum;
    }
};

int main() {
    Solution sol;

    cout << sol.addStrings("11", "123") << endl;      // Expected: 134
    cout << sol.addStrings("456", "77") << endl;      // Expected: 533
    cout << sol.addStrings("0", "0") << endl;         // Expected: 0
    cout << sol.addStrings("999", "1") << endl;       // Expected: 1000

    return 0;
}
