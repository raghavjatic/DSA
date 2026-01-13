/*
 * Problem: Happy Number
 * Description: Write an algorithm to determine if a number n is happy.
 * A happy number is a number defined by repeatedly replacing the number
 * by the sum of the squares of its digits until it equals 1, or it loops endlessly.
 * Link: https://leetcode.com/problems/happy-number/
 *
 * Author: Raghav Jatic
 * Date: 13th January 2026
 */

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        
        while (n != 1) {
            if (seen.count(n))   // cycle detected
                return false;
            
            seen.insert(n);
            
            int sum = 0;
            while (n != 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};

int main() {
    Solution sol;

    cout << sol.isHappy(19) << endl; // Expected: 1 (true)
    cout << sol.isHappy(2) << endl;  // Expected: 0 (false)

    return 0;
}
