/*
 * Problem: To Lower Case
 * Description: Given a string s, return the string after replacing every uppercase
 * letter with the same lowercase letter.
 * Link: https://leetcode.com/problems/to-lower-case/
 *
 * Author: Raghav Jatic
 * Date: 25th December 2025
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                s[i]=s[i]+32;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;

    cout << sol.toLowerCase("Hello") << endl;      // Expected: hello
    cout << sol.toLowerCase("LOVELY") << endl;     // Expected: lovely
    cout << sol.toLowerCase("al&phaBET") << endl; // Expected: al&phabet

    return 0;
}
