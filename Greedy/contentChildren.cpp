/*
 * Problem: Assign Cookies
 * Description: Given two integer arrays g and s, where g[i] is the greed factor of the i-th child
 * and s[j] is the size of the j-th cookie, return the maximum number of content children.
 * Link: https://leetcode.com/problems/assign-cookies/
 *
 * Author: Raghav Jatic
 * Date: 19th January 2026
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        while(j<s.size() && i<g.size())
        {
            while(j<s.size() && i<g.size())
            {
                if(s[j]<g[i])
                {
                    j=j+1;
                }
                else
                {
                    j=j+1;
                    i=i+1;
                }
            }
        }
        return i;
    }
};

int main() {
    Solution sol;

    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    cout << sol.findContentChildren(g, s) << endl;
    // Expected output: 1

    return 0;
}
