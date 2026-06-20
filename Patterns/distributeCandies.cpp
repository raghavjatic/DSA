/*
 * Problem: Distribute Candies
 * Description: Return the maximum number of different candy types that Alice can eat
 *              when she can only eat half of the candies.
 * Link: https://leetcode.com/problems/distribute-candies/
 * Author: Raghav Jatic
 * Date: 20th June 2026
 * Pattern type: Hash Set
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st(candyType.begin(), candyType.end());

        int n = candyType.size();
        int s = st.size();

        if(s < n / 2)
            return s;

        return n / 2;
    }
};

int main()
{
    Solution sol;

    vector<int> candyType1 = {1, 1, 2, 2, 3, 3};
    vector<int> candyType2 = {1, 1, 2, 3};
    vector<int> candyType3 = {6, 6, 6, 6};

    cout << "Output 1: "
         << sol.distributeCandies(candyType1)
         << endl;

    cout << "Output 2: "
         << sol.distributeCandies(candyType2)
         << endl;

    cout << "Output 3: "
         << sol.distributeCandies(candyType3)
         << endl;

    return 0;
}