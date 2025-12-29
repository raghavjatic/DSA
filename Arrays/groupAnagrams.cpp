/*
 * Problem: Group Anagrams
 * Description: Given an array of strings, group the anagrams together.
 * You can return the answer in any order.
 * Link: https://leetcode.com/problems/group-anagrams/
 *
 * Author: Raghav Jatic
 * Date: 30th December 2025
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // map to group words having same sorted form
        unordered_map<string, vector<string>> mp;

        // go through each word
        for (int i = 0; i < strs.size(); i++) {

            string word = strs[i];      // original word
            string key = word;          // copy for sorting

            sort(key.begin(), key.end());

            // add original word to its anagram group
            mp[key].push_back(word);
        }

        // prepare final answer
        vector<vector<string>> ans;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = sol.groupAnagrams(strs);

    // Print result
    for (auto &group : result) {
        for (auto &word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
