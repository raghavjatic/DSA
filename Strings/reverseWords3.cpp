/*
 * Problem: Reverse Words in a String III
 * Description: Given a string s, reverse the characters of each word in the string
 * while still preserving whitespace and initial word order.
 * Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/
 *
 * Author: Raghav Jatic
 * Date: 23rd December 2025
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverse(string word)
    {
        int len=word.size();
        int f,r;
        f=0;
        r=len-1;
        while(f<=r)
        {
            char temp=word[f];
            word[f]=word[r];
            word[r]=temp;
            f=f+1;
            r=r-1;
        }
        return word;
    }

    string reverseWords(string s) {
        string word="";
        string ans="";
        int len=s.size();
        int i=0;
        while(i<len)
        {
            while(i<len && s[i]!=' ')
            {
                word.push_back(s[i]);
                i=i+1;
            }
            word=reverse(word);
            for(int j=0;j<word.size();j++)
            {
                ans.push_back(word[j]);
            }
            while(s[i]==' ')
            {
                ans.push_back(s[i]);
                i=i+1;
            }
            word="";
        }
        return ans;
    }
};

int main() {
    Solution sol;

    cout << sol.reverseWords("Let's take LeetCode contest") << endl;
    // Expected: "s'teL ekat edoCteeL tsetnoc"

    cout << sol.reverseWords("God Ding") << endl;
    // Expected: "doG gniD"

    return 0;
}
