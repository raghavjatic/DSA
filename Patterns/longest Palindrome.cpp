/*
 * Problem: Longest Palindrome
 * Description: Find the length of the longest palindrome that can be built with the letters of the given string.
 * Link: https://leetcode.com/problems/longest-palindrome/
 * Author: Raghav Jatic
 * Date: 19th June 2026
 * Pattern type: Hash Map (Frequency Counting)
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int n = s.size();

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            mp[s[i]] += 1;
        }

        int flag = 0;

        for(auto it : mp)
        {
            if((it.second) % 2 != 0)
            {
                if(flag != 1)
                {
                    ans += it.second;
                    flag = 1;
                }
                else
                {
                    ans += (it.second) - 1;
                }
            }
            else
            {
                ans += it.second;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    string s1 = "abccccdd";
    string s2 = "a";

    cout << "Output 1: "
         << sol.longestPalindrome(s1)
         << endl;

    cout << "Output 2: "
         << sol.longestPalindrome(s2)
         << endl;

    return 0;
}