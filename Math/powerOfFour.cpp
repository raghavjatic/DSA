/*
 * Problem: Power of Four
 * Description: Given an integer n, return true if it is a power of four.
 * Otherwise, return false.
 * Link: https://leetcode.com/problems/power-of-four/
 *
 * Author: Raghav Jatic
 * Date: 2nd January 2026
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;

        while(n!=1)
        {
            int d=n%4;
            if(d!=0)
                return false;
            n/=4;
        }
        return true;
    }
};

int main() {
    Solution sol;

    cout << sol.isPowerOfFour(16) << endl; // Expected: 1 (true)
    cout << sol.isPowerOfFour(5) << endl;  // Expected: 0 (false)
    cout << sol.isPowerOfFour(1) << endl;  // Expected: 1 (true)
    cout << sol.isPowerOfFour(64) << endl; // Expected: 1 (true)

    return 0;
}
