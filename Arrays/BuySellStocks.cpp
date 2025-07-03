/*
 * Problem: Best Time to Buy and Sell Stock
 * Description: You are given an array `prices` where `prices[i]` is the price of a given stock on the i-th day. 
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 * 
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 * Author: Raghav Jatic
 * Date: 3rd July 2025
 */

#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, min_price = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (min_price > prices[i]) {
                min_price = prices[i];
            } else {
                max_profit = max(max_profit, prices[i] - min_price);
            }
        }
        return max_profit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = sol.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}
