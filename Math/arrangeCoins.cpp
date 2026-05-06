/**
 * Problem: Arranging Coins
 * Description: You have n coins and want to build a staircase with these coins. Return the number of complete rows you can form.
 * Link: https://leetcode.com/problems/arranging-coins/
 * Author: Raghav Jatic
 * Date: 7th May 2026
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
        int cnt =0;
        while(n>=i)
        {
            n = n-i;
            ++cnt;
            i=i+1;
        }
        return cnt;
    }
};

int main() {
    Solution obj;

    int n = 8;

    int result = obj.arrangeCoins(n);

    cout << "Complete Rows: " << result << endl;

    return 0;
}