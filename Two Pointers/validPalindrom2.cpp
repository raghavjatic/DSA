/*
 * Problem: Valid Palindrome II
 * Description: Given a string s, return true if the string can be made
 *              a palindrome by deleting at most one character.
 * Link: https://leetcode.com/problems/valid-palindrome-ii/
 * Author: Raghav Jatic
 * Date: 10th June 2026
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    bool isPalindrome(string &s, int left, int right)
    {
        while(left < right)
        {
            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while(left < right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                // Try deleting either the left character or the right character
                return isPalindrome(s, left + 1, right) ||
                       isPalindrome(s, left, right - 1);
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;

    string s1 = "aba";
    string s2 = "abca";
    string s3 = "abc";

    cout << boolalpha;

    cout << "Input: " << s1 << "\nOutput: "
         << sol.validPalindrome(s1) << "\n\n";

    cout << "Input: " << s2 << "\nOutput: "
         << sol.validPalindrome(s2) << "\n\n";

    cout << "Input: " << s3 << "\nOutput: "
         << sol.validPalindrome(s3) << "\n";

    return 0;
}