/*
 * Problem: Find All Anagrams in a String
 * Description: Find all starting indices of p's anagrams in s.
 * Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * Author: Raghav Jatic
 * Date: 16th June 2026
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(vector<int> s, vector<int> p)
    {
        for(int j = 0; j < 26; j++)
        {
            if(s[j] != p[j])
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> freq(26);
        vector<int> freq2(26);

        int a = 0;
        int n = s.size();
        int n2 = p.size();

        if(n < n2)
            return ans;

        int b = n2 - 1;

        // Frequency of p
        for(int i = 0; i < n2; i++)
        {
            freq2[p[i] - 'a']++;
        }

        // Frequency of first window in s
        for(int i = 0; i < n2; i++)
        {
            freq[s[i] - 'a']++;
        }

        for(a = 0; b < n - 1; a++)
        {
            if(isAnagram(freq, freq2))
                ans.push_back(a);

            freq[s[a] - 'a']--;
            freq[s[b + 1] - 'a']++;

            b++;
        }

        if(isAnagram(freq, freq2))
            ans.push_back(a);

        return ans;
    }
};

int main()
{
    Solution sol;

    string s1 = "cbaebabacd";
    string p1 = "abc";

    string s2 = "abab";
    string p2 = "ab";

    vector<int> result1 = sol.findAnagrams(s1, p1);
    vector<int> result2 = sol.findAnagrams(s2, p2);

    cout << "Output 1: ";
    for(int index : result1)
        cout << index << " ";
    cout << endl;

    cout << "Output 2: ";
    for(int index : result2)
        cout << index << " ";
    cout << endl;

    return 0;
}