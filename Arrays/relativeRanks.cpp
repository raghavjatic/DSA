/*
 * Problem: Relative Ranks
 * Description: Given an array of scores, return their relative ranks.
 * The top three scores get medals, and the rest get their rank number.
 * Link: https://leetcode.com/problems/relative-ranks/
 *
 * Author: Raghav Jatic
 * Date: 30th December 2025
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    int binarySearch(vector<int>& v, int target) {
        int l = 0, r = v.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (v[mid] == target)
                return mid;
            else if (v[mid] > target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1; // not found
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> s=score;
        sort(s.begin(),s.end(), greater<int>());
        int n=s.size();
        int gold=s[0];
        int silver;
        int bronze;
        if(n>1)
            silver =s[1];
        if(n>2)
            bronze =s[2];
        vector<string> answer;

        for(int i=0;i<n;i++)
        {
            if(score[i] == gold)
                answer.push_back("Gold Medal");
            else if(score[i] == silver)
                answer.push_back("Silver Medal");
            else if(score[i] == bronze)
                answer.push_back("Bronze Medal");
            else
                answer.push_back(to_string((binarySearch(s,score[i])+1)));
        }
        return answer;
    }
};

//more refined solution
// vector<pair<int,int>> v;
// for(int i = 0; i < n; i++)
//     v.push_back({score[i], i});

// sort(v.begin(), v.end(), greater<>());

// vector<string> ans(n);

// for(int i = 0; i < n; i++) {
//     if(i == 0) ans[v[i].second] = "Gold Medal";
//     else if(i == 1) ans[v[i].second] = "Silver Medal";
//     else if(i == 2) ans[v[i].second] = "Bronze Medal";
//     else ans[v[i].second] = to_string(i + 1);
// }

int main() {
    Solution sol;

    vector<int> score = {5, 4, 3, 2, 1};
    vector<string> result = sol.findRelativeRanks(score);

    for (auto &s : result) {
        cout << s << " ";
    }
    cout << endl;
    // Expected output: Gold Medal Silver Medal Bronze Medal 4 5

    return 0;
}
