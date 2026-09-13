/*
============================================================
Problem: 2904. Shortest and Lexicographically Smallest Beautiful String
Description: Given a binary string s and an integer k, return
             the shortest substring containing exactly k ones.
             If multiple such substrings have the same length,
             return the lexicographically smallest one.
Link: https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/
Author: Raghav Jatic
Date: 14th September 2026
============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string lexiSmaller(string s, string t)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i] > t[i])
            return t;
            else if(s[i] < t[i])
            return s;
            else
            continue;
        }
        return s;
    }


    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int ones = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '1')
            ones += 1;
            if(ones >= k)
            break;
        }
        if(ones < k)
        return ans;

        ans = s; //at least s is beautiful

        //main check
        for(int i=0;i<s.size();i++)
        {
            ones = 0;
            string substr="";
            for(int j=i;j<s.size();j++)
            {
                if(s[j] == '1')
                ones += 1;
                substr += s[j];

                if(ones == k)
                {
                    if(ans.size() == substr.size())
                    ans = lexiSmaller(ans, substr);
                    else if(ans.size() > substr.size())
                    ans = substr;
                    break;
                } 
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    string s;
    int k;

    cin >> s >> k;

    cout << solution.shortestBeautifulSubstring(s, k) << endl;

    return 0;
}