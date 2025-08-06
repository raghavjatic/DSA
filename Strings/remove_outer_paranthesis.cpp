/*
 * Problem: Remove Outermost Parentheses
 * Description: A valid parentheses string is either empty "", "(A)", or "AB", 
 * where A and B are valid parentheses strings. A primitive string is a non-empty valid parentheses string that cannot be split.
 * Given a valid parentheses string s, remove the outermost parentheses of every primitive string in the primitive decomposition of s.
 * 
 * Link: https://leetcode.com/problems/remove-outermost-parentheses/
 *
 * Author: Raghav Jatic
 * Date: 3rd August 2025
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                if (depth > 0) result += c; // not the outermost '('
                depth++;
            } else if (c == ')') {
                depth--;
                if (depth > 0) result += c; // not the outermost ')'
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "(()())(())(()(()))";

    string result = sol.removeOuterParentheses(s);
    cout << "After Removing Outermost Parentheses: " << result << endl;

    return 0;
}
