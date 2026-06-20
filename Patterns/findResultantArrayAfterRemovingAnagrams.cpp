/*
 * Problem: Find Resultant Array After Removing Anagrams
 * Description: Remove consecutive strings that are anagrams of the previous string.
 * Link: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
 * Author: Raghav Jatic
 * Date: June 2026
 * Pattern type: Hash Map + Simulation
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAna(string s, string p)
    {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(int i = 0; i < s.size(); i++)
        {
            mp1[s[i]] += 1;
        }

        for(int i = 0; i < p.size(); i++)
        {
            mp2[p[i]] += 1;
        }

        if(mp1 == mp2)
            return true;

        return false;
    }

    vector<string> removeAnagrams(vector<string>& words) {

        string s, p;
        s = words[0];

        vector<string> ans;

        ans.push_back(words[0]);

        for(int i = 1; i < words.size(); i++)
        {
            if(!isAna(ans.back(), words[i]))
            {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<string> words1 = {"abba", "baba", "bbaa", "cd", "cd"};
    vector<string> words2 = {"a", "b", "c", "d", "e"};

    vector<string> result1 = sol.removeAnagrams(words1);
    vector<string> result2 = sol.removeAnagrams(words2);

    cout << "Output 1: ";
    for(string s : result1)
        cout << s << " ";
    cout << endl;

    cout << "Output 2: ";
    for(string s : result2)
        cout << s << " ";
    cout << endl;

    return 0;
}