/**
 * Problem: Find K Pairs with Smallest Sums
 * Description: You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
 * Define a pair (u, v) which consists of one element from nums1 and one element from nums2.
 * Return the k pairs (u, v) with the smallest sums.
 * Link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
 * Author: Raghav Jatic
 * Date: 23rd March 2026
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,int k) {

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>pq;


        for (int i = 0; i < nums1.size(); i++) {

                int a = nums1[i];
                int b = nums2[0];
                int c = a + b;
                pq.push({c, {i, 0}});
            }

        vector<vector<int>> ans;

        while(k-- && !pq.empty()) {
            vector<int> curr;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            // actual values
            int a = nums1[i];
            int b = nums2[j];

            curr.push_back(a);
            curr.push_back(b);
            pq.pop();
            ans.push_back(curr);

            if(j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    vector<vector<int>> result = obj.kSmallestPairs(nums1, nums2, k);

    cout << "K Smallest Pairs:" << endl;
    for (auto &pair : result) {
        cout << pair[0] << ", " << pair[1] << endl;
    }

    return 0;
}