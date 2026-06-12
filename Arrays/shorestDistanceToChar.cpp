/*
 * Problem: Shortest Distance to a Character
 * Description: For each character in the string, find the shortest distance
 *              to the given target character.
 * Link: https://leetcode.com/problems/shortest-distance-to-a-character/
 * Author: Raghav Jatic
 * Date: 11th June 2026
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {

        int n = s.size();
        vector<int> ans(n);

        int prev = -n;

        // Left to Right
        for(int i = 0; i < n; i++)
        {
            if(s[i] == c)
                prev = i;

            ans[i] = i - prev;
        }

        prev = 2 * n;

        // Right to Left
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == c)
                prev = i;

            ans[i] = min(ans[i], prev - i);
        }

        return ans;
    }
};

int main() {

    Solution sol;

    string s = "loveleetcode";
    char c = 'e';

    vector<int> result = sol.shortestToChar(s, c);

    cout << "Output: ";

    for(int distance : result)
    {
        cout << distance << " ";
    }

    cout << endl;

    return 0;
}