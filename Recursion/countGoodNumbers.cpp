/*
 * Problem: Count Good Numbers
 * Description: A digit string is good if the digits at even indices are even and the
 * digits at odd indices are prime. Given an integer n, return the number of good digit
 * strings of length n. Since the answer may be very large, return it modulo 10^9 + 7.
 * Link: https://leetcode.com/problems/count-good-numbers/
 *
 * Author: Raghav Jatic
 * Date: 3rd February 2026
 */

#include <iostream>
using namespace std;

class Solution {
public:

    static const long long MOD = 1000000007;

    long long power(long long x, long long n)
    {
        long long ans = 1;

        while(n > 0)
        {
            // If n is odd
            if(n % 2 == 1)
            {
                ans = (ans * x) % MOD;
            }

            // Square x
            x = (x * x) % MOD;

            // Divide n by 2
            n = n / 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long e;    //denotes the number of places out of n where even digits can be stored
        long long p;    //prime digits can be stored
        if(n % 2 != 0)
            e= n/2 + 1;
        else
            e=n/2;
        p=n-e;
        
        long long part1 = power(5, e);
        long long part2 = power(4, p);

        return (part1 * part2) % MOD;
    }
};

int main() {
    Solution sol;

    cout << sol.countGoodNumbers(1) << endl;  // Expected: 5
    cout << sol.countGoodNumbers(4) << endl;  // Expected: 400
    cout << sol.countGoodNumbers(50) << endl; // Large output (mod 1e9+7)

    return 0;
}
