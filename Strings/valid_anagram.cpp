/*
 * Problem: Valid Anagram
 * Description: Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * 
 * Link: https://leetcode.com/problems/valid-anagram/
 *
 * Author: Raghav Jatic
 * Date: 3rd August 2025
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        if (l1 != l2) return false;

        int sCount[256] = {};
        int tCount[256] = {};
        for (int i = 0; i < l1; i++) {
            ++sCount[s[i]];
            ++tCount[t[i]];
        }

        for (int i = 0; i < 256; i++) {
            if (sCount[i] != tCount[i]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";

    bool result = sol.isAnagram(s, t);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
