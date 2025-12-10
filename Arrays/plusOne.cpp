// Problem: Plus One
// Description: Given a non-empty array of decimal digits representing a non-negative integer, increment the integer by one.
// Link: https://leetcode.com/problems/plus-one/
// Author: Raghav Jatic
// Date: 11th December 2025

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size()-1;
        int n=len+1;
        
        if(digits[len]==9)
        {
        while(digits[len]==9 && len!=0)
        {
            digits[len]=0;
            len=len-1;
        }
        if(digits[0]==9 && len==0)
        {
            vector<int> result(n + 1, 0);
            result[0] = 1;
            return result;
        }

        digits[len]=digits[len]+1;
        return digits;
        }

        else
        digits[len]=digits[len]+1;
        return digits;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3};
    vector<int> ans1 = sol.plusOne(nums1);
    cout << "Result: ";
    for (int x : ans1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {9, 9, 9};
    vector<int> ans2 = sol.plusOne(nums2);
    cout << "Result: ";
    for (int x : ans2) cout << x << " ";
    cout << endl;

    vector<int> nums3 = {4, 3, 2, 1};
    vector<int> ans3 = sol.plusOne(nums3);
    cout << "Result: ";
    for (int x : ans3) cout << x << " ";
    cout << endl;

    return 0;
}
