/*
 * Problem: Longest Substring with At Least K Repeating Characters
 * Description: Find the length of the longest substring such that
 *              every character in the substring appears at least k times.
 * Link: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
 * Author: Raghav Jatic
 * Date: 13th June 2026
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    int solve(string& s, int left, int right, int k)
    {
        if(right - left + 1 < k)
            return 0;

        vector<int> freq(26, 0);

        for(int i = left; i <= right; i++)
        {
            freq[s[i] - 'a']++;
        }

        for(int i = left; i <= right; i++)
        {
            if(freq[s[i] - 'a'] < k)
            {
                int leftPart = solve(s, left, i - 1, k);
                int rightPart = solve(s, i + 1, right, k);

                return max(leftPart, rightPart);
            }
        }

        return right - left + 1;
    }

    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size() - 1, k);
    }
};

int main()
{
    Solution sol;

    string s1 = "aaabb";
    int k1 = 3;

    string s2 = "ababbc";
    int k2 = 2;

    cout << "Output 1: "
         << sol.longestSubstring(s1, k1)
         << endl;

    cout << "Output 2: "
         << sol.longestSubstring(s2, k2)
         << endl;

    return 0;
}