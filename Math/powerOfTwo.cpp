/**
 * Problem: Power of Two
 * Description: Given an integer n, return true if it is a power of two. Otherwise, return false.
 * Link: https://leetcode.com/problems/power-of-two/
 * Author: Raghav Jatic
 * Date: 7th May 2026
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
        return true;
        if(n <= 0)
            return false;
        if (n % 2 != 0)
            return false;

        while (n % 2 == 0) 
        {
            n = n / 2;
        }
        if(n == 1)
        return true;
        return false;
    }
};

int main() {
    Solution obj;

    int n = 16;

    bool result = obj.isPowerOfTwo(n);

    if(result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}