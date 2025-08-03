/*
 * Problem: Rotate String
 * Description: Given two strings s and goal, return true if and only if s can become goal after some number of shifts.
 * A shift involves moving the leftmost character of s to the rightmost position.
 * 
 * Link: https://leetcode.com/problems/rotate-string/
 *
 * Author: Raghav Jatic
 * Date: 3rd August 2025
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int l = s.length();
        int i = 0;
        bool result = false;
        string s2;

        while (i != l) {
            s2 = s.substr(i, l - i) + s.substr(0, i);
            if (s2 == goal) {
                result = true;
                break;
            } else {
                i++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s = "abcde";
    string goal = "cdeab";

    bool result = sol.rotateString(s, goal);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
