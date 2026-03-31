/**
 * Problem: Maximum Nesting Depth of the Parentheses
 * Description: Given a valid parentheses string s, return the maximum nesting depth of the parentheses.
 * Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 * Author: Raghav Jatic
 * Date: 31st March 2026
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int ans;
        int max;
        ans=max=0;
        for(int i=0;i<n;i++)
        {
            char t = s[i];
            if(t == '(')
            {
                ans = ans+1;
                if(max < ans)
                max = ans;
            }
            if(t == ')')
            ans = ans - 1;
        }

        return max;
    }
};

int main() {
    Solution obj;

    string s = "(1+(2*3)+((8)/4))+1";

    int result = obj.maxDepth(s);

    cout << "Maximum Nesting Depth: " << result << endl;

    return 0;
}