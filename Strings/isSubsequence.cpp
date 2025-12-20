/*
 * Problem: Is Subsequence
 * Description: Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
 * A subsequence of a string is a new string formed from the original string by deleting some (or none)
 * of the characters without disturbing the relative positions of the remaining characters.
 * Link: https://leetcode.com/problems/is-subsequence/
 *
 * Author: Raghav Jatic
 * Date: 20th December 2025
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j,k;
        j=k=0;
        int l1=s.size();
        int l2=t.size();
        while(j<l1 && k<l2)
        {
            if(s[j]==t[k])
            {
                j=j+1;
                k=k+1;
            }
            else
            {
                k=k+1;
            }
        }
        if(j==l1)
        return true;
        return false;
    }
};

int main() {
    Solution sol;

    cout << sol.isSubsequence("abc", "ahbgdc") << endl; // Expected: 1 (true)
    cout << sol.isSubsequence("axc", "ahbgdc") << endl; // Expected: 0 (false)
    cout << sol.isSubsequence("", "ahbgdc") << endl;    // Expected: 1 (true)
    cout << sol.isSubsequence("b", "abc") << endl;      // Expected: 1 (true)

    return 0;
}
