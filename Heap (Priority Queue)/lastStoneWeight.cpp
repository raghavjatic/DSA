/**
 * Problem: Last Stone Weight
 * Description: You are given an array of integers stones where stones[i] is the weight of the ith stone.
 * Each turn, we choose the two heaviest stones and smash them together.
 * If both stones are equal, they are destroyed. If not, the remaining stone has weight equal to their difference.
 * Return the weight of the last remaining stone, or 0 if none remain.
 * Link: https://leetcode.com/problems/last-stone-weight/
 * Author: Raghav Jatic
 * Date: 21st March 2026
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int> > heap;
        for(int i=0;i<stones.size();i++)
        {
            heap.push(stones[i]);
        }
        int a,b;
        while(heap.size()>1)
        {
        a=heap.top();
        heap.pop();
        b=heap.top();
        heap.pop();
        int c= abs(a-b);
        if(c != 0)
        heap.push(c);
        }
        if(heap.empty())
        return 0;
        return heap.top();
    }
};

int main() {
    Solution obj;
    vector<int> stones = {2,7,4,1,8,1};

    int result = obj.lastStoneWeight(stones);

    cout << "Last Stone Weight: " << result << endl;

    return 0;
}