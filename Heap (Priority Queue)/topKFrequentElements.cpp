/**
 * Problem: Top K Frequent Elements
 * Description: Given an integer array nums and an integer k, return the k most frequent elements.
 * You may return the answer in any order.
 * Link: https://leetcode.com/problems/top-k-frequent-elements/
 * Author: Raghav Jatic
 * Date: 22nd March 2026
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // count frequency
        for (int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
        }

        // max heap {freq, element}
        priority_queue<pair<int,int>> heap;

        for (auto it : mp) {
            heap.push({it.second, it.first});
        }

        vector<int> ans;

        // get top k
        for (int i = 0; i < k; i++) {
            ans.push_back(heap.top().second);
            heap.pop();
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> result = obj.topKFrequent(nums, k);

    cout << "Top K Frequent Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}