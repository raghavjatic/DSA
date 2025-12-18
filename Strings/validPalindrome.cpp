/*
 * Problem: Valid Palindrome
 * Description: Given a string s, determine if it is a palindrome, considering only alphanumeric characters
 * and ignoring cases.
 * Link: https://leetcode.com/problems/valid-palindrome/
 *
 * Author: Raghav Jatic
 * Date: 19th December 2025
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l=s.size();
        int f,r;
        f=0;
        r=l-1;
        for(int i=0;i<l;i++)
        {
            if(!((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')))
            s[i]='#';
            else {
                s[i] = tolower(s[i]);
            }
        }

        while(f<r)
        {
            while(f<r && s[f]=='#')
            {
                f=f+1;
            }
            while(f<r && s[r]=='#')
            {
                r=r-1;
            }
            if(s[f]!=s[r])
            return false;
            f=f+1;
            r=r-1;
        }
        return true;
    }
};

int main() {
    Solution sol;

    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl; // Expected: 1 (true)
    cout << sol.isPalindrome("race a car") << endl;                     // Expected: 0 (false)
    cout << sol.isPalindrome(" ") << endl;                               // Expected: 1 (true)
    cout << sol.isPalindrome("0P") << endl;                              // Expected: 0 (false)

    return 0;
}
