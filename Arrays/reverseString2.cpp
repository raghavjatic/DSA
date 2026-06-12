/*******************************************************
 * Problem: Reverse String II
 * Link: https://leetcode.com/problems/reverse-string-ii/
 * Author: Raghav Jatic
 * Date: 4th June 2026
 *******************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {

        for (int i = 0; i < s.size(); i += 2 * k) {

            int left = i;
            int right = min(i + k - 1, (int)s.size() - 1);

            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};

int main() {
    Solution sol;

    string s = "abcdefg";
    int k = 2;

    cout << sol.reverseStr(s, k) << endl; // bacdfeg

    return 0;
}