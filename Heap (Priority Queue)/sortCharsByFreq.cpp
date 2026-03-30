/**
 * Problem: Sort Characters By Frequency
 * Description: Given a string s, sort it in decreasing order based on the frequency of the characters.
 * The frequency of a character is the number of times it appears in the string.
 * Return the sorted string.
 * Link: https://leetcode.com/problems/sort-characters-by-frequency/
 * Author: 23rd Raghav Jatic
 * Date: March 2026
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++)
        {
            char c=s[i];
            mp[c]++;
        }

        priority_queue<pair<int, char>> pq;

        for(auto it : mp)
        {
            pq.push({it.second, it.first});
        }     

        string ans = "";
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            for(int i = 0; i < top.first; i++) {
            ans += top.second;
            }
        }

        return ans;

    }
};

int main() {
    Solution obj;
    string s = "tree";

    string result = obj.frequencySort(s);

    cout << "Sorted by Frequency: " << result << endl;

    return 0;
}