/*
 * Problem: Partition Labels
 * Description: Partition the string into as many parts as possible so that
 *              each letter appears in at most one part.
 * Link: https://leetcode.com/problems/partition-labels/
 * Author: Raghav Jatic
 * Date: 25th June 2026
 * Pattern type: Frequency Maps
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            // Only note the last occurrence of each character
            last[s[i]] = i;
        }

        int start = 0;
        int end = 0;

        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            // Extend the current partition if needed
            end = max(end, last[s[i]]);

            // We can safely partition here
            if(i == end)
            {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    string s1 = "ababcbacadefegdehijhklij";
    string s2 = "eccbbbbdec";

    vector<int> ans1 = sol.partitionLabels(s1);
    vector<int> ans2 = sol.partitionLabels(s2);

    cout << "Output 1: ";
    for(int x : ans1)
        cout << x << " ";
    cout << endl;

    cout << "Output 2: ";
    for(int x : ans2)
        cout << x << " ";
    cout << endl;

    return 0;
}