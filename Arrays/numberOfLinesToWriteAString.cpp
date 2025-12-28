/*
 * Problem: Number of Lines To Write String
 * Description: You are given a string s and an array widths that contains the widths
 * of each lowercase English letter. Write s with a maximum of 100 units per line.
 * Return the number of lines required and the width used by the last line.
 * Link: https://leetcode.com/problems/number-of-lines-to-write-string/
 *
 * Author: Raghav Jatic
 * Date: 29th December 2025
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int curr = 0;

        for(int i = 0; i < s.size(); i++) {
            int w = widths[s[i] - 'a'];

            if(curr + w > 100) {
                lines++;
                curr = w;
            } else {
                curr += w;
            }
        }

        vector<int> ans;
        ans.push_back(lines);
        ans.push_back(curr);

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> widths = {
        10,10,10,10,10,10,10,10,10,10,
        10,10,10,10,10,10,10,10,10,10,
        10,10,10,10,10,10
    };
    string s = "abcdefghijklmnopqrstuvwxyz";

    vector<int> result = sol.numberOfLines(widths, s);

    cout << result[0] << " " << result[1] << endl;
    // Expected output: 3 60

    return 0;
}
