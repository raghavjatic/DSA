/**
 * Problem: Lemonade Change
 * Description: At a lemonade stand, each lemonade costs $5. Customers pay with $5, $10, or $20 bills. Return true if you can provide correct change to every customer.
 * Link: https://leetcode.com/problems/lemonade-change/
 * Author: Raghav Jatic
 * Date: 31st March 2026
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for (int bill : bills)
        {
            if (bill == 5) 
            {
                five++;
            }
            else if (bill == 10) 
            {
                if (five == 0) return false;
                five--;
                ten++;
            }
            else 
            { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    vector<int> bills = {5, 5, 5, 10, 20};

    bool result = obj.lemonadeChange(bills);

    if(result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}