/*
 * Problem: Detect Capital
 * Description: We define the usage of capitals in a word to be correct when either
 * all letters are capitals, all letters are not capitals, or only the first letter is capital.
 * Given a string word, return true if the usage of capitals in it is correct.
 * Link: https://leetcode.com/problems/detect-capital/
 *
 * Author: Raghav Jatic
 * Date: 23rd December 2025
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int capCount = 0;

        for (int i=0;i<word.size();i++)
        {
            if (word[i] >= 'A' && word[i] <= 'Z')
                capCount++;
        }

        // Case 1: all letters capital
        if (capCount == n)
            return true;

        // Case 2: all letters small
        if (capCount == 0)
            return true;

        // Case 3: only first letter capital
        if (capCount == 1 && word[0] >= 'A' && word[0] <= 'Z')
            return true;

        return false;
    }
};

int main() {
    Solution sol;

    cout << sol.detectCapitalUse("USA") << endl;     // Expected: 1 (true)
    cout << sol.detectCapitalUse("leetcode") << endl;// Expected: 1 (true)
    cout << sol.detectCapitalUse("Google") << endl;  // Expected: 1 (true)
    cout << sol.detectCapitalUse("FlaG") << endl;    // Expected: 0 (false)

    return 0;
}
