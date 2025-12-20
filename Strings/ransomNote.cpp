/*
 * Problem: Ransom Note
 * Description: Given two strings ransomNote and magazine, return true if ransomNote can be constructed
 * by using the letters from magazine and false otherwise.
 * Each letter in magazine can only be used once in ransomNote.
 * Link: https://leetcode.com/problems/ransom-note/
 *
 * Author: Raghav Jatic
 * Date: 20th December 2025
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len=magazine.size();
        vector<int> hash(27,0);
        for(int i=0;i<len;i++)
        {
            char c=magazine[i];
            hash[c-'a']+=1;
        }

        int len2=ransomNote.size();
        for(int i=0;i<len2;i++)
        {
            char c=ransomNote[i];
            if(hash[c-'a']==0)
            return false;
            else
            {
                hash[c-'a']-=1;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    cout << sol.canConstruct("a", "b") << endl;        // Expected: 0 (false)
    cout << sol.canConstruct("aa", "ab") << endl;      // Expected: 0 (false)
    cout << sol.canConstruct("aa", "aab") << endl;     // Expected: 1 (true)
    cout << sol.canConstruct("abc", "cbad") << endl;   // Expected: 1 (true)

    return 0;
}
