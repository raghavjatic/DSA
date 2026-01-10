/*
 * Problem: Power of Three
 * Description: Given an integer n, return true if it is a power of three.
 * Otherwise, return false.
 * Link: https://leetcode.com/problems/power-of-three/
 *
 * Author: Raghav Jatic
 * Date: 1st January 2026
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;

        while(n!=1)
        {
            int d=n%3;
            if(d!=0)
                return false;
            n/=3;
        }
        return true;
    }
};

int main() {
    Solution sol;

    cout << sol.isPowerOfThree(27) << endl; // Expected: 1 (true)
    cout << sol.isPowerOfThree(0) << endl;  // Expected: 0 (false)
    cout << sol.isPowerOfThree(9) << endl;  // Expected: 1 (true)
    cout << sol.isPowerOfThree(45) << endl; // Expected: 0 (false)

    return 0;
}

//alternate method
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         return n > 0 && 1162261467 % n == 0;
//     }
// };
