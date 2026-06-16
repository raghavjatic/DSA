/*
 * Problem: Fruit Into Baskets
 * Description: Find the length of the longest subarray containing
 *              at most two distinct fruit types.
 * Link: https://leetcode.com/problems/fruit-into-baskets/
 * Author: Raghav Jatic
 * Date: 17th June 2026
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> freq;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < fruits.size(); right++)
        {
            freq[fruits[right]]++;

            while(freq.size() > 2)
            {
                freq[fruits[left]]--;

                if(freq[fruits[left]] == 0)
                {
                    freq.erase(fruits[left]);
                }

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> fruits1 = {1, 2, 1};
    vector<int> fruits2 = {0, 1, 2, 2};
    vector<int> fruits3 = {1, 2, 3, 2, 2};

    cout << "Output 1: "
         << sol.totalFruit(fruits1)
         << endl;

    cout << "Output 2: "
         << sol.totalFruit(fruits2)
         << endl;

    cout << "Output 3: "
         << sol.totalFruit(fruits3)
         << endl;

    return 0;
}