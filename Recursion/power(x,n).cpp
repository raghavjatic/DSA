/*
 * Problem: Pow(x, n)
 * Description: Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
 * Link: https://leetcode.com/problems/powx-n/
 *
 * Author: Raghav Jatic
 * Date: 3rd February 2026
 */

#include <iostream>
using namespace std;

//good Binary Exponentiation logic
class Solution {
public:
    double power(double x, long long n)
    {
        if(n == 0)
            return 1.0;
        double half = power(x , n/2);

        if(n%2 == 0)
            return half*half;
        else
            return half*half*x;
    }

    double myPow(double x, int n) {
        
        long long N;
        N = n;
        double X = x;
        if(N<0)
        {
            X = 1/x;
            N=-N;
        }
        return power(X , N);
    }
};

int main() {
    Solution sol;

    cout << sol.myPow(2.0, 10) << endl;   // Expected: 1024
    cout << sol.myPow(2.0, -2) << endl;   // Expected: 0.25
    cout << sol.myPow(3.0, 5) << endl;    // Expected: 243

    return 0;
}
