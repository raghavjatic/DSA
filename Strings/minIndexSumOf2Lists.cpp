/*
 * Problem: Minimum Index Sum of Two Lists
 * Description: Given two lists of strings list1 and list2, find all common strings
 * with the minimum index sum. Return them in any order.
 * Link: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
 *
 * Author: Raghav Jatic
 * Date: 24th December 2025
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {
        int l1, l2;
        l1 = list1.size();
        l2 = list2.size();

        unordered_map<string, int> mp; // to store word and index of list1
        unordered_map<string, int>
            mp2; // to store word and index of common words

        vector<string> ans;

        for (int i = 0; i < l1; i++) {
            mp[list1[i]] = i;
        }

        int minSum;
        int sum;

        int flag = 0;

        for (int j = 0; j < l2; j++) {
            if (mp.find(list2[j]) != mp.end()) // list2[j] exists
            {
                int i = mp[list2[j]];
                sum = i + j;

                if (flag == 0) // for initializing minSum for the first time
                {
                    minSum = sum;
                    flag = 1;
                }

                if (sum <= minSum) {
                    minSum = sum;
                    mp2[list2[j]] = sum;
                }
            }
        }

        for (auto it : mp2) {
            if (it.second == minSum) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};

    vector<string> result = sol.findRestaurant(list1, list2);

    for (auto &s : result) {
        cout << s << " ";
    }
    cout << endl;
    // Expected output: Shogun

    return 0;
}
