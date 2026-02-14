/*
 * Problem: Combination Sum
 * Description: Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen numbers sum to target.
 * You may use the same number an unlimited number of times.
 * Link: https://leetcode.com/problems/combination-sum/
 *
 * Author: Raghav Jatic
 * Date: 14th February 2026
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void findCombinations(int ind, vector<int>& arr, int target, vector<int>& ds)
    {
        if(ind == arr.size())
        {
            if(target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }

        if(arr[ind] <= target)
        {
            ds.push_back(arr[ind]);
            findCombinations(ind, arr, target-arr[ind], ds);
            ds.pop_back();
        }
        findCombinations(ind+1, arr, target, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds; //data structure;
        findCombinations(0, candidates, target, ds);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    for (auto &vec : result) {
        cout << "[ ";
        for (int x : vec) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
