// Problem: Add Binary
// Description: Given two binary strings a and b, return their sum as a binary string.
// Link: https://leetcode.com/problems/add-binary/
// Author: Raghav Jatic
// Date: 11th December 2025

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0)
            {
                sum += a[i] - '0';
                i--;
            }

            if (j >= 0)
            {
                sum += b[j] - '0';
                j--;
            }

            // current bit of result = sum % 2
            res += (sum % 2) + '0';

            // update carry (either 0 or 1)
            carry = sum / 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;

    string a1 = "11", b1 = "1";
    cout << "Sum: " << sol.addBinary(a1, b1) << endl;

    string a2 = "1010", b2 = "1011";
    cout << "Sum: " << sol.addBinary(a2, b2) << endl;

    string a3 = "0", b3 = "0";
    cout << "Sum: " << sol.addBinary(a3, b3) << endl;

    return 0;
}
