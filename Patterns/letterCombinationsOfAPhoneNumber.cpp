/*
 * Problem: Letter Combinations of a Phone Number
 * Description: Return all possible letter combinations that the number could represent.
 * Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * Author: Raghav Jatic
 * Date: June 2026
 * Pattern type: Backtracking
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> ans;
    unordered_map<int, string> mp;

    void solve(int index, string current, string digits) {
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        string letters = mp[digit];

        for (char ch : letters) {
            solve(index + 1, current + ch, digits);
        }

        return;
    }

    vector<string> letterCombinations(string digits) {

        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        if (digits.empty())
            return {};

        solve(0, "", digits);

        return ans;
    }
};

int main() {
    Solution sol;

    string digits1 = "23";
    string digits2 = "";

    vector<string> result1 = sol.letterCombinations(digits1);
    vector<string> result2 = sol.letterCombinations(digits2);

    cout << "Output 1: ";
    for (string s : result1)
        cout << s << " ";
    cout << endl;

    cout << "Output 2: ";
    for (string s : result2)
        cout << s << " ";
    cout << endl;

    return 0;
}