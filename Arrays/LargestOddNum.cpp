/*
 * Problem: Largest Odd Number in String
 * Description: You are given a string num, representing a large integer. 
 * Return the largest-valued odd integer (as a string) that is a non-empty substring of num, 
 * or an empty string "" if no odd integer exists.
 * 
 * Link: https://leetcode.com/problems/largest-odd-number-in-string/
 *
 * Author: Raghav Jatic
 * Date: 7th July 2025
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        string result = "";
        for (int i = num.length() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                result = num.substr(0, i + 1);
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string num = "354270186";

    string result = sol.largestOddNumber(num);
    cout << "Largest Odd Number: " << result << endl;

    return 0;
}
