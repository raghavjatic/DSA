/*
 * Problem: Word Pattern
 * Description: Given a pattern and a string s, find if s follows the same pattern.
 * Here follow means a full match, such that there is a bijection between a letter
 * in pattern and a non-empty word in s.
 * Link: https://leetcode.com/problems/word-pattern/
 *
 * Author: Raghav Jatic
 * Date: 19th December 2025
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> charToWord(26, "");
        unordered_map<string, char> wordToChar;

        int i = 0, j = 0;
        int n = pattern.size();

        for (i = 0; i < n; i++) {
            if (j >= s.size()) return false;

            string word = "";
            while (j < s.size() && s[j] != ' ') {
                word += s[j];
                j++;
            }
            j++; // skip space

            char p = pattern[i];
            int idx = p - 'a';

            // char → word check
            if (charToWord[idx] == "") {
                charToWord[idx] = word;
            } else if (charToWord[idx] != word) {
                return false;
            }

            // word → char check
            if (wordToChar.count(word)) {
                if (wordToChar[word] != p)
                    return false;
            } else {
                wordToChar[word] = p;
            }
        }

        // extra words check
        if (j < s.size()) return false;

        return true;
    }
};

int main() {
    Solution sol;

    cout << sol.wordPattern("abba", "dog cat cat dog") << endl; // Expected: 1 (true)
    cout << sol.wordPattern("abba", "dog cat cat fish") << endl; // Expected: 0 (false)
    cout << sol.wordPattern("aaaa", "dog cat cat dog") << endl; // Expected: 0 (false)
    cout << sol.wordPattern("abba", "dog dog dog dog") << endl; // Expected: 0 (false)

    return 0;
}
