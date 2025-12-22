/*
 * Problem: Reverse Vowels of a String
 * Description: Given a string s, reverse only all the vowels in the string and return it.
 * Link: https://leetcode.com/problems/reverse-vowels-of-a-string/
 *
 * Author: Raghav Jatic
 * Date: 21st December 2025
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int f = 0;
        string ans;
        ans = s;
        int r = s.size() - 1;
        while (f < r) {
            while (f < r && !(ans[f] == 'a' || ans[f] == 'e' || ans[f] == 'i' ||
                              ans[f] == 'o' || ans[f] == 'u' || ans[f] == 'A' ||
                              ans[f] == 'E' || ans[f] == 'I' || ans[f] == 'O' ||
                              ans[f] == 'U'))
                f = f + 1;

            while (f < r && !(ans[r] == 'a' || ans[r] == 'e' || ans[r] == 'i' ||
                              ans[r] == 'o' || ans[r] == 'u' || ans[r] == 'A' ||
                              ans[r] == 'E' || ans[r] == 'I' || ans[r] == 'O' ||
                              ans[r] == 'U'))
                r = r - 1;

            if (f < r) {

                char temp = ans[f];
                ans[f] = ans[r];
                ans[r] = temp;
                f = f + 1;
                r = r - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    cout << sol.reverseVowels("hello") << endl;        // Expected: holle
    cout << sol.reverseVowels("leetcode") << endl;     // Expected: leotcede
    cout << sol.reverseVowels("aA") << endl;           // Expected: Aa
    cout << sol.reverseVowels(".,") << endl;           // Expected: .,

    return 0;
}
