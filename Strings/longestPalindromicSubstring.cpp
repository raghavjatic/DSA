#include <bits/stdc++.h>
using namespace std;

/*
Problem: Longest Palindromic Substring
Description: Find the longest substring which is a palindrome.
Link: https://leetcode.com/problems/longest-palindromic-substring/
Author: Raghav Jatic
Date: 31st March 2026
*/

class Solution {
public:
    string expand(string s, int left, int right)
    {
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string ans = "";

        for(int i = 0; i < s.size(); i++)
        {
            // odd length
            string odd = expand(s, i, i);

            // even length
            string even = expand(s, i, i + 1);

            if(odd.size() > ans.size())
                ans = odd;

            if(even.size() > ans.size())
                ans = even;
        }

        return ans;
    }
};

int main() {
    Solution obj;
    string s = "babad";

    cout << "Longest Palindromic Substring: " 
         << obj.longestPalindrome(s) << endl;

    return 0;
}