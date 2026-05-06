/**
 * Problem: Nim Game
 * Description: You are playing the Nim Game. Given the number of stones n, return true if you can win the game assuming both players play optimally.
 * Link: https://leetcode.com/problems/nim-game/
 * Author: Raghav Jatic
 * Date: 7th May 2026
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {

        if(n % 4 == 0)
            return false;

        return true;
    }
};

int main() {
    Solution obj;

    int n = 7;

    bool result = obj.canWinNim(n);

    if(result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}