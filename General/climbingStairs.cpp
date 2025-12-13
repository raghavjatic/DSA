/*
 * Problem: Climbing Stairs
 * Description: You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * Link: https://leetcode.com/problems/climbing-stairs/
 *
 * Author: Raghav Jatic
 * Date: 12th December 2025
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a,b,c;
        a=1;
        b=2;
        if(n==1)
        return a;
        if(n==2)
        return b;
        for(int i=3;i<=n;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
};

int main() {
    Solution sol;

    cout << sol.climbStairs(1) << endl; // Expected: 1
    cout << sol.climbStairs(2) << endl; // Expected: 2
    cout << sol.climbStairs(3) << endl; // Expected: 3
    cout << sol.climbStairs(4) << endl; // Expected: 5
    cout << sol.climbStairs(5) << endl; // Expected: 8

    return 0;
}
