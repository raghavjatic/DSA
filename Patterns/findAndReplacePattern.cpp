/*
 * Problem: Find and Replace Pattern
 * Description: Find all words that match the given pattern using a bijective character mapping.
 * Link: https://leetcode.com/problems/find-and-replace-pattern/
 * Author: Raghav Jatic
 * Date: June 2026
 * Pattern type: Hash Map (Character Mapping)
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool func(string word, string pattern)
    {
        // Now we'll check if word and pattern match or not
        unordered_map<char, char> mapping;

        for(int i = 0; i < word.size(); i++)
        {
            // Build mapping
            char cw = word[i];
            char cp = pattern[i];

            if(mapping.find(cw) == mapping.end())
            {
                mapping[cw] = cp;
            }
        }

        // Check mapping consistency
        for(int i = 0; i < word.size(); i++)
        {
            char cw = word[i];
            char cp = pattern[i];

            if(mapping[cw] != cp)
                return false;
        }

        // Check bijection property
        unordered_map<char, int> mp;

        for(auto it : mapping)
        {
            mp[it.second]++;
        }

        for(auto it : mp)
        {
            if(it.second != 1)
                return false;
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        int n = words.size();
        int np = pattern.size();

        vector<string> ans;

        for(int i = 0; i < n; i++)
        {
            string word = words[i];
            int nw = word.size();

            if(nw == np && func(word, pattern))
                ans.push_back(word);
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string pattern = "abb";

    vector<string> result = sol.findAndReplacePattern(words, pattern);

    cout << "Output: ";

    for(string word : result)
        cout << word << " ";

    cout << endl;

    return 0;
}