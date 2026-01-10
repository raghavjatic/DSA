/*
 * Problem: Add Digits
 * Description: Given an integer num, repeatedly add all its digits until the result
 * has only one digit, and return it.
 * Link: https://leetcode.com/problems/add-digits/
 *
 * Author: Raghav Jatic
 * Date: 11th January 2026
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while(true)
        {
            if(num  / 10 == 0)
                return num;
            else
            {
                int n=num;
                int sum=0;
                while(n != 0)
                {
                    sum = sum + (n%10);
                    n = n / 10;
                }
                num = sum;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;

    cout << sol.addDigits(38) << endl; // Expected: 2
    cout << sol.addDigits(0) << endl;  // Expected: 0
    cout << sol.addDigits(9) << endl;  // Expected: 9

    return 0;
}
