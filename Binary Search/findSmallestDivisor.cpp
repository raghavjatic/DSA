/*
 * Problem: Find the Smallest Divisor Given a Threshold
 * Description: Given an array of integers nums and an integer threshold, choose a positive
 * integer divisor such that the sum of all the results of dividing each number in nums by
 * the divisor (rounded up) is less than or equal to threshold.
 * Return the smallest such divisor.
 * Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
 *
 * Author: Raghav Jatic
 * Date: 30th January 2026
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int sum(vector<int>& nums, int divisor)
    {
        int total=0;
        for(int j=0;j<nums.size();j++)
        {
            int que= (int)ceil((double)nums[j] / divisor);
            total = total + que;
        }
        return total;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=nums[0];
        for(int i=1;i<n;i++)    //finding max element
        {
            if(nums[i] > high)
                high=nums[i];
        }

        int ans;
        while(low <= high)
        {
            int mid= (low+high)/2;
            int t=sum(nums , mid);
            if(t <= threshold) {
                ans = mid;        // valid answer
                high = mid - 1;   // try smaller
            }
            else {
                low = mid + 1;    // need bigger divisor
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout << sol.smallestDivisor(nums, threshold) << endl;
    // Expected output: 5

    return 0;
}
