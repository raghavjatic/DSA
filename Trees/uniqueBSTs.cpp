/*
 * Problem: Unique Binary Search Trees
 * Description: Given an integer n, return the number of structurally unique BST's
 * (binary search trees) which has exactly n nodes of unique values from 1 to n.
 * Link: https://leetcode.com/problems/unique-binary-search-trees/
 *
 * Author: Raghav Jatic
 * Date: 18th January 2026
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<long long> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;

    cout << sol.numTrees(3) << endl; // Expected: 5
    cout << sol.numTrees(1) << endl; // Expected: 1
    cout << sol.numTrees(5) << endl; // Expected: 42

    return 0;
}
