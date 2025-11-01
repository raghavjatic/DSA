// Problem: Find the Index of the First Occurrence in a String
// Description: Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
// Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Author: Raghav Jatic
// Date: 1st November 2025

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len=haystack.size();
        int len2=needle.size();
        // if(haystack==needle) return 0;
        int j=0;
        for(int i=0;i<len-len2+1;i++)
        {
            if(haystack[i]==needle[j])
            {
                string s=haystack.substr(i,len2);
                if(s==needle)
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string haystack = "sadbutsad";
    string needle = "sad";
    cout << "First occurrence index: " << sol.strStr(haystack, needle) << endl;

    haystack = "leetcode";
    needle = "leeto";
    cout << "First occurrence index: " << sol.strStr(haystack, needle) << endl;

    return 0;
}
