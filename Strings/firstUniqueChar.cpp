/*
 * Problem: First Unique Character in a String
 * Description: Given a string s, find the first non-repeating character in it
 * and return its index. If it does not exist, return -1.
 * Link: https://leetcode.com/problems/first-unique-character-in-a-string/
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
    int firstUniqChar(string s) {
        int len=s.size();
        vector<int> hash(26,0);
        for(int i=0;i<len;i++)
        {
            char c=s[i];
            hash[c-'a']+=1;
        }

        for(int i=0;i<len;i++)
        {
            char c=s[i];
            if(hash[c-'a']==1)
            return i;
        }
        return -1;
    }
};

int main() {
    Solution sol;

    cout << sol.firstUniqChar("leetcode") << endl;      // Expected: 0
    cout << sol.firstUniqChar("loveleetcode") << endl;  // Expected: 2
    cout << sol.firstUniqChar("aabb") << endl;          // Expected: -1

    return 0;
}
