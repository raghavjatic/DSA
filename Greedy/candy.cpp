/*
 * Problem: Candy
 * Description: There are n children standing in a line. Each child is assigned a rating value.
 * You are giving candies to these children subjected to the following requirements:
 * - Each child must have at least one candy.
 * - Children with a higher rating get more candies than their neighbors.
 * Return the minimum number of candies you need to distribute.
 * Link: https://leetcode.com/problems/candy/
 *
 * Author: Raghav Jatic
 * Date: 24th January 2026
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int i=1;
        int sum=1;
        int peak=0;
        int down=0;
        while(i<ratings.size())
        {

            while(i<ratings.size() && ratings[i] == ratings[i-1])
            {
                sum = sum+ 1;
                i=i+1;
            }

            peak =1;

            while(i<ratings.size() && ratings[i] > ratings[i-1])
            {
                int j=1;
                peak= peak +1;
                sum = sum+ peak;
                i=i+1;
            }

            down =1; 

            while(i<ratings.size() && ratings[i] < ratings[i-1])
            {
                int j=1;
                sum = sum+ down;
                down= down + 1;
                i=i+1;
            }

            if(down > peak)
                sum=sum + (down - peak);

        }
        return sum;
    }
};

int main() {
    Solution sol;

    vector<int> ratings1 = {1, 0, 2};
    cout << sol.candy(ratings1) << endl; // Expected: 5

    vector<int> ratings2 = {1, 2, 2};
    cout << sol.candy(ratings2) << endl; // Expected: 4

    return 0;
}
