/**
 * Problem: Valid Parentheses
 * Description: Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * Link: https://leetcode.com/problems/valid-parentheses/
 * Author: Raghav Jatic
 * Date: 24th September 2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.size();
        char ch;
        char ch2;
        for (int i = 0; i < len; i++) {
            ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.empty())
                    return false;
                ch2 = st.top();
                st.pop();
                if ((ch == ')' && ch2 != '(') || (ch == '}' && ch2 != '{') ||
                    (ch == ']' && ch2 != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    string s = "({[]})";

    if (sol.isValid(s))
        cout << s << " is valid parentheses." << endl;
    else
        cout << s << " is NOT valid parentheses." << endl;

    return 0;
}
