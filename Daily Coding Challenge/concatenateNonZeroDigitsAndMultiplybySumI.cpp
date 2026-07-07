/*
============================================================
Problem: 3754. Concatenate Non-Zero Digits and Multiply by Sum I
Pattern type: Number Manipulation
Description:
Form a new integer by concatenating all non-zero digits of the
given number in their original order. Compute the sum of its
digits and return x * sum.
LeetCode: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/
Author: Raghav Jatic
Date: 7th July 2026
============================================================
*/

#include <iostream>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x=0;
        while(n != 0)
        {
            int dg = n%10;
            if(dg != 0)
            {
                x = x*10 + dg;
                sum += dg;
            }
            n =n/10;
        }

        n=x;
        x=0;
        
        while(n != 0)
        {
            int dg = n%10;
            x = x*10 + dg;
            n =n/10;
        }

        long long ans = x * sum;
        return ans;
    }
};

int main() {
    Solution obj;

    int n = 105203;
    cout << "Input: " << n << endl;
    cout << "Output: " << obj.sumAndMultiply(n) << endl;

    return 0;
}