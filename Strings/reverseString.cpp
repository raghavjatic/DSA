/*
 * Problem: Reverse String
 * Description: Write a function that reverses a string. The input string is given as an array of characters s.
 * You must do this by modifying the input array in-place with O(1) extra memory.
 * Link: https://leetcode.com/problems/reverse-string/
 *
 * Author: Raghav Jatic
 * Date: 21st December 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int f=0;
        int r=s.size()-1;
        while(f<=r)
        {
            char temp=s[f];
            s[f]=s[r];
            s[r]=temp;
            f=f+1;
            r=r-1;
        }
    }
};

int main() {
    Solution sol;

    vector<char> s1 = {'h','e','l','l','o'};
    sol.reverseString(s1);
    for(char c : s1) cout << c;
    cout << endl;   // Expected: olleh

    vector<char> s2 = {'H','a','n','n','a','h'};
    sol.reverseString(s2);
    for(char c : s2) cout << c;
    cout << endl;   // Expected: hannaH

    return 0;
}
