/*
 * Problem: Koko Eating Bananas
 * Description: Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
 * Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas
 * and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead.
 * Koko wants to eat all the bananas within h hours. Return the minimum integer k such that she can eat
 * all the bananas within h hours.
 * Link: https://leetcode.com/problems/koko-eating-bananas/
 *
 * Author: Raghav Jatic
 * Date: 30th January 2026
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hn(vector<int>& piles, int mid) // to calculate number of hours needed
    {
        int total = 0;
        int n1 = piles.size();
        for (int j = 0; j < n1; j++) {
            total = total + (piles[j] / mid);
            if (piles[j] % mid > 0)
                total += 1;
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high;
        high = piles[0];
        int ans;
        int n = piles.size();

        for (int i = 0; i < n; i++) // finding max of piles
        {
            if (piles[i] > high)
                high = piles[i];
        }

        while (low < high) {
            int mid = (low + high) / 2;
            ans = mid;
            int h1 = hn(piles, mid);
            if (h1 <= h)
                high = mid; // try smaller
            else
                low = mid + 1; // need faster
        }
        return low;
    }
};

int main() {
    Solution sol;

    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << sol.minEatingSpeed(piles, h) << endl;
    // Expected output: 4

    return 0;
}
