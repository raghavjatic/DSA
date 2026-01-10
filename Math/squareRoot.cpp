/*
Problem: Sqrt(x)
Description:
Given a non-negative integer x, return the floor of the square root of x.
Link: https://leetcode.com/problems/sqrtx/
Author: Raghav Jatic
Date: 12th December 2025
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x, ans = 0;
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long sq = mid * mid;
            if (sq <= x) {
                ans = mid;       // mid is a candidate
                l = mid + 1;     // try larger
            } else {
                r = mid - 1;     // too large
            }
        }
        return (int)ans;
    }
};

int main() {
    Solution sol;

    cout << sol.mySqrt(4) << endl;   // Expected: 2
    cout << sol.mySqrt(8) << endl;   // Expected: 2
    cout << sol.mySqrt(0) << endl;   // Expected: 0
    cout << sol.mySqrt(1) << endl;   // Expected: 1
    cout << sol.mySqrt(2147395599) << endl; // Large test

    return 0;
}
