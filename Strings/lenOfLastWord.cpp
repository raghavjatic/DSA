// Problem: Length of Last Word
// Description: Given a string s consisting of words and spaces, return the length of the last word in the string.
// Link: https://leetcode.com/problems/length-of-last-word/
// Author: Raghav Jatic
// Date: 1st November 2025

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.size();
        int c=0;
        while(s[len-1]==' ') len=len-1;
        for(int i = len-1;i>=0;i--)
        {
            if(s[i]!=' ') c=c+1;
            else return c;
        }
        return c;
    }
};

int main() {
    Solution sol;
    string s1 = "Hello World";
    cout << "Length of last word: " << sol.lengthOfLastWord(s1) << endl;

    string s2 = "   fly me   to   the moon  ";
    cout << "Length of last word: " << sol.lengthOfLastWord(s2) << endl;

    string s3 = "luffy is still joyboy";
    cout << "Length of last word: " << sol.lengthOfLastWord(s3) << endl;

    return 0;
}
