/*
 * Problem: Base 7
 * Description: Given an integer num, return a string of its base 7 representation.
 * Link: https://leetcode.com/problems/base-7/
 *
 * Author: Raghav Jatic
 * Date: 23rd December 2025
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)
        return "0";

        bool negative = false;
        if (num < 0) {
            negative = true;
            num = -num;
        }

        string ans="";
        while(num>0)
        {
            int rem=num%7;
            ans.push_back(rem + '0');
            num=num/7;
        }

        if(negative==true)
        ans.push_back('-');
        reverse(ans.begin(),ans.end());

        return ans;
    }
};

int main() {
    Solution sol;

    cout << sol.convertToBase7(100) << endl;   // Expected: 202
    cout << sol.convertToBase7(-7) << endl;    // Expected: -10
    cout << sol.convertToBase7(0) << endl;     // Expected: 0
    cout << sol.convertToBase7(49) << endl;    // Expected: 100

    return 0;
}
