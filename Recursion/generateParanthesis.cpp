/*
 * Problem: Generate Parentheses
 * Description: Given n pairs of parentheses, write a function to generate all
 * combinations of well-formed parentheses.
 * Link: https://leetcode.com/problems/generate-parentheses/
 *
 * Author: Raghav Jatic
 * Date: 4th February 2026
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> result;

    void backtrack(string current, int open, int close, int n) {
        // If the current string is complete
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if possible
        if (open < n) {
            backtrack(current + "(", open + 1, close, n);
        }

        // Add ')' if valid
        if (close < open) {
            backtrack(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return result;
    }
};

int main() {
    Solution sol;

    int n = 3;
    vector<string> res = sol.generateParenthesis(n);

    for (auto &s : res) {
        cout << s << endl;
    }

    return 0;
}
