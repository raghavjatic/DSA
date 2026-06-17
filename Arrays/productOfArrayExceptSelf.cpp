/*
 * Problem: Product of Array Except Self
 * Description: Return an array answer such that answer[i] is equal
 *              to the product of all the elements of nums except nums[i],
 *              without using division.
 * Link: https://leetcode.com/problems/product-of-array-except-self/
 * Author: Raghav Jatic
 * Date: 18th June 2026
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        // Edge case
        if(n == 1)
            return {1};

        vector<int> prefix(n);
        vector<int> suffix(n);

        // prefix[i] excludes nums[i]
        prefix[0] = 1;
        prefix[1] = nums[0];

        for(int i = 2; i < n; i++)
        {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        // suffix[i] excludes nums[i]
        suffix[n-1] = 1;
        suffix[n-2] = nums[n-1];

        for(int i = n-3; i >= 0; i--)
        {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++)
        {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {-1, 1, 0, -3, 3};

    vector<int> ans1 = sol.productExceptSelf(nums1);
    vector<int> ans2 = sol.productExceptSelf(nums2);

    cout << "Output 1: ";
    for(int x : ans1)
        cout << x << " ";
    cout << endl;

    cout << "Output 2: ";
    for(int x : ans2)
        cout << x << " ";
    cout << endl;

    return 0;
}