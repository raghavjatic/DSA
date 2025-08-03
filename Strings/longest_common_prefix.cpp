/*
 * Problem: Longest Common Prefix
 * Description: Write a function to find the longest common prefix string 
 * amongst an array of strings. If there is no common prefix, return an empty string "".
 * 
 * Link: https://leetcode.com/problems/longest-common-prefix/
 *
 * Author: Raghav Jatic
 * Date: 3rd August 2025
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix, prefix1;
        string word;
        prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            word = strs[i];
            for (int j = 0; j < word.length(); j++) {
                if (word[j] == prefix[j]) {
                    prefix1 += word[j];
                } else break;
            }
            prefix = prefix1;
            prefix1 = "";
        }
        return prefix;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};

    string result = sol.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
