/*
 * Problem: Number of Segments in a String
 * Description: Given a string s, return the number of segments in the string.
 * A segment is defined to be a contiguous sequence of non-space characters.
 * Link: https://leetcode.com/problems/number-of-segments-in-a-string/
 *
 * Author: Raghav Jatic
 * Date: 21st December 2025
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int l=s.size();
        int cnt=0;
        for(int i=0;i<l;i++)
        {
            if (s[i] == ' ') continue;
            while(i<l && s[i]!=' ')
            i=i+1;
            cnt=cnt+1;
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    cout << sol.countSegments("Hello, my name is John") << endl; // Expected: 5
    cout << sol.countSegments("Hello") << endl;                  // Expected: 1
    cout << sol.countSegments("    ") << endl;                   // Expected: 0
    cout << sol.countSegments("a b  c   d") << endl;             // Expected: 4

    return 0;
}
