/*
 * Problem: Counting Bits
 * Description: Given an integer n, return an array ans of length n + 1 such that
 * for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
 * Link: https://leetcode.com/problems/counting-bits/
 *
 * Author: Raghav Jatic
 * Date: 2nd January 2026
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1);
        bits[0]=0;
        for(int i=1;i<=n;i++)
        {
            bits[i]= bits[i/2] + (i%2);
        }
        return bits;
    }
};

int main() {
    Solution sol;

    int n = 5;
    vector<int> result = sol.countBits(n);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    // Expected output: 0 1 1 2 1 2

    return 0;
}
