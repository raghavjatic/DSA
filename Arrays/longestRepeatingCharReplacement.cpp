/*
 * Problem: Longest Repeating Character Replacement
 * Description: Given a string and an integer k, return the length of the
 *              longest substring that can be obtained by replacing at most
 *              k characters so that all characters in the substring are the same.
 * Link: https://leetcode.com/problems/longest-repeating-character-replacement/
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
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for(int right = 0; right < s.size(); right++)
        {
            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            while((right - left + 1) - maxFreq > k)
            {
                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    string s1 = "ABAB";
    int k1 = 2;

    string s2 = "AABABBA";
    int k2 = 1;

    cout << "Output 1: "
         << sol.characterReplacement(s1, k1)
         << endl;

    cout << "Output 2: "
         << sol.characterReplacement(s2, k2)
         << endl;

    return 0;
}