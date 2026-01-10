/*
 * Problem: Valid Perfect Square
 * Description: Given a positive integer num, return true if num is a perfect square.
 * Do not use any built-in library function such as sqrt.
 * Link: https://leetcode.com/problems/valid-perfect-square/
 *
 * Author: Raghav Jatic
 * Date: 4th January 2026
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<1)
            return false;
        long long l=1;
        long long h=num;
        while(l<=h)
        {
            long long mid= l+(h-l)/2;
            if(mid * mid == num)
                return true;
            else if((mid * mid) < num)
                l=mid + 1;
            else
                h=mid - 1;
        }
        return false;
    }
};

int main() {
    Solution sol;

    cout << sol.isPerfectSquare(16) << endl; // Expected: 1 (true)
    cout << sol.isPerfectSquare(14) << endl; // Expected: 0 (false)
    cout << sol.isPerfectSquare(1) << endl;  // Expected: 1 (true)
    cout << sol.isPerfectSquare(808201) << endl; // Expected: 1 (true)

    return 0;
}
