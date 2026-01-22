/*
 * Problem: Valid Parenthesis String
 * Description: Given a string s containing only three types of characters: '(' , ')'
 * and '*', return true if s is valid.
 * The '*' character can be treated as a single '(' or ')' or an empty string.
 * Link: https://leetcode.com/problems/valid-parenthesis-string/
 *
 * Author: Raghav Jatic
 * Date: 21st January 2026
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        if(s[0]== ')') return false;
        int min,max;
        min=max=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                min=min+1;
                max=max+1;
            }
            else if(s[i]==')')
            {
                min=min-1;
                max=max-1;
            }
            else // "*"
            {
                min=min-1;
                max=max+1;
            }
            if(min < 0) min=0;
            if(max < 0) return false;
        }
        if(min==0)
            return true;
        return false;
    }
};

int main() {
    Solution sol;

    cout << sol.checkValidString("()") << endl;        // Expected: 1
    cout << sol.checkValidString("(*)") << endl;       // Expected: 1
    cout << sol.checkValidString("(*))") << endl;      // Expected: 1
    cout << sol.checkValidString("(()") << endl;       // Expected: 0

    return 0;
}
