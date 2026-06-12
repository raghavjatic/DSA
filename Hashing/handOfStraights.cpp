/**
 * Problem: Hand of Straights
 * Description: Given an array of integers hand and an integer groupSize, return true if it is possible to rearrange the cards into groups where each group consists of groupSize consecutive cards.
 * Link: https://leetcode.com/problems/hand-of-straights/
 * Author: Raghav Jatic
 * Date: 30th March 2026
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)
        return false;

        map<int, int> mp;

        for(int i = 0; i < n; i++)
        {
            mp[hand[i]]++;
        }

        for(auto it : mp)
        {
            int start = it.first;
            int freq = it.second;

            if(freq > 0)
            {
                for(int i = 0; i < groupSize; i++)
                {
                    if(mp[start + i] < freq)
                    return false;
                    mp[start + i] -= freq;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    int groupSize = 3;

    bool result = obj.isNStraightHand(hand, groupSize);

    if(result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}