/*
 * Problem: Longest Substring Without Repeating Characters
 * Description: Given a string s, find the length of the longest substring without repeating characters.
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Author: Raghav Jatic
 * Date: 12th December 2025
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector <int> hash(256,-1);
        int n=s.size();
        int l=0,r=0;
        int maxlen=0;
        int len=0;

        while(r<n)
        {
            if(hash[s[r]]!=-1)
            {
                if(hash[s[r]]>=l)
                {
                    l=hash[s[r]]+1;
                }
            }
            len=r-l+1;
            maxlen=max(maxlen,len);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;        
    }
};

int main() {
    Solution sol;

    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl; // Expected: 3 ("abc")
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl;    // Expected: 1 ("b")
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;   // Expected: 3 ("wke")
    cout << sol.lengthOfLongestSubstring("") << endl;         // Expected: 0
    cout << sol.lengthOfLongestSubstring("au") << endl;       // Expected: 2

    return 0;
}
