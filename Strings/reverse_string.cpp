/*
 * Problem: Reverse Words in a String
 * Description: Given an input string s, reverse the order of the words. 
 * A word is defined as a sequence of non-space characters. The words are separated by at least one space.
 * Return a string of the words in reverse order concatenated by a single space.
 * 
 * Link: https://leetcode.com/problems/reverse-words-in-a-string/
 *
 * Author: Raghav Jatic
 * Date: 3rd August 2025
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int firstindex = 0, lastindex = s.size() - 1;
        int len = s.size();

        // Remove leading spaces        
        while (firstindex < len && s[firstindex] == ' ')
            firstindex++;

        // Remove trailing spaces
        while (lastindex >= 0 && s[lastindex] == ' ')
            lastindex--;

        string s2 = "";
        string word = "";
        int i = lastindex;

        while (i >= firstindex) {
            while (i >= 0 && s[i] != ' ') {
                word = s[i] + word;
                i--;
            }

            // Skip spaces between words
            while (i >= firstindex && s[i] == ' ')
                i--;

            s2 = s2 + " " + word;
            word = "";
        }

        s2.erase(0, 1); // remove leading space
        return s2;
    }
};

int main() {
    Solution sol;
    string input = "  hello   world  ";

    string result = sol.reverseWords(input);
    cout << "Reversed Words: \"" << result << "\"" << endl;

    return 0;
}
