/*
 * Problem: Container With Most Water
 * Description: Given n non-negative integers representing an elevation map, 
 * where the width of each bar is 1, find two lines that together with the x-axis 
 * form a container that holds the most water.
 * Link: https://leetcode.com/problems/container-with-most-water/
 *
 * Author: Raghav Jatic
 * Date: 15th December 2025
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i,j,a;
        int area,maxarea;
        area=maxarea=0;
        int l=height.size();



        // for(i=0;i<l;i++)
        // {
        //     for(j=i+1;j<l;j++)
        //     {
        //         a=min(height[i],height[j]);              this solution gives O(n^2) results.
        //         area=(j-i)*a;
        //         if(area>maxarea)
        //         maxarea=area;
        //     }
        // }


        i=0;
        j=l-1;
        while(i<j)
        {
            a=min(height[i],height[j]);
                area=(j-i)*a;
                if(area>maxarea)
                maxarea=area;

                if(height[i]<height[j]) i=i+1;
                else j=j-1;
        }

        return maxarea;
    }
};

int main() {
    Solution sol;

    vector<int> height1 = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(height1) << endl; // Expected: 49

    vector<int> height2 = {1,1};
    cout << sol.maxArea(height2) << endl; // Expected: 1

    vector<int> height3 = {4,3,2,1,4};
    cout << sol.maxArea(height3) << endl; // Expected: 16

    return 0;
}
