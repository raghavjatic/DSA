/**
 * Problem: Divide Array in Sets of K Consecutive Numbers
 * Description: Given an array of integers nums and an integer k, return true if it is possible to divide this array into sets of k consecutive numbers.
 * Link: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
 * Author: Raghav Jatic
 * Date: 30th March 2026
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0)
        return false;

        map<int, int> mp;

        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for(auto it : mp)
        {
            int start = it.first;
            int freq = it.second;

            if(freq > 0)
            {
                for(int i = 0; i < k; i++)
                {
                    if(mp[start + i] < freq)
                    return false;
                    mp[start + i] -= freq;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1,2,3,3,4,4,5,6};
    int k = 4;

    bool result = obj.isPossibleDivide(nums, k);

    if(result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}