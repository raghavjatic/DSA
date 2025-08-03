/*
 * Problem: Isomorphic Strings
 * Description: Given two strings s and t, determine if they are isomorphic.
 * Two strings are isomorphic if characters in s can be replaced to get t,
 * with each character mapping to one other unique character (no two map to same).
 * 
 * Link: https://leetcode.com/problems/isomorphic-strings/
 *
 * Author: Raghav Jatic
 * Date: 3rd August 2025
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        int sToT[256], tToS[256];
        fill(begin(sToT), end(sToT), -1);
        fill(begin(tToS), end(tToS), -1);

        for (int i = 0; i < s.length(); ++i) {
            char chS = s[i];
            char chT = t[i];

            if (sToT[chS] == -1 && tToS[chT] == -1) {
                sToT[chS] = chT;
                tToS[chT] = chS;
            } else {
                if (sToT[chS] != chT || tToS[chT] != chS)
                    return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    string s = "foo", t = "bar";
    cout << (solution.isIsomorphic(s, t) ? "true" : "false") << endl;
    return 0;
}
