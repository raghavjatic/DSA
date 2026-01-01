/*
 * Problem: Ugly Number
 * Description: An ugly number is a positive integer whose prime factors only include
 * 2, 3, and 5. Given an integer n, return true if n is an ugly number.
 * Link: https://leetcode.com/problems/ugly-number/
 *
 * Author: Raghav Jatic
 * Date: 1st January 2026
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)
            return false;
        while(n!=1)
        {
            if(n%2==0)
                n=n/2;
            else if(n%3==0)
                n=n/3;
            else if(n%5==0)
                n=n/5;
            else
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    cout << sol.isUgly(6) << endl;   // Expected: 1 (true)
    cout << sol.isUgly(1) << endl;   // Expected: 1 (true)
    cout << sol.isUgly(14) << endl;  // Expected: 0 (false)

    return 0;
}
