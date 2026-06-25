/*
 * Problem: Set Mismatch
 * Description: Find the duplicated number and the missing number in the array.
 * Link: https://leetcode.com/problems/set-mismatch/
 * Author: Raghav Jatic
 * Date: 22nd June 2026
 * Pattern type: Hash Map (Frequency Counting)
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        unordered_map<int, int> mp;

        for(int num : nums)
            mp[num]++;

        vector<int> ans(2);

        for(int i = 1; i <= nums.size(); i++)
        {
            if(mp[i] == 2)
                ans[0] = i;      // duplicate

            if(mp[i] == 0)
                ans[1] = i;      // missing
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 4};
    vector<int> nums2 = {1, 1};

    vector<int> ans1 = sol.findErrorNums(nums1);
    vector<int> ans2 = sol.findErrorNums(nums2);

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