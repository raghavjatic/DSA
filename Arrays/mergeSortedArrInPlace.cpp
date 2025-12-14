/*
 * Problem: Merge Sorted Array
 * Description: You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
 * and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * Merge nums2 into nums1 as one sorted array in-place.
 * Link: https://leetcode.com/problems/merge-sorted-array/
 *
 * Author: Raghav Jatic
 * Date: 15th December 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {



        // int j,k,l;
        // j=k=l=0;
        // int size = m + n;
        // vector<int> c(size);
        // while (j < m && k < n)
        // {
        //     if(nums1[j]<nums2[k])
        //     {
        //         c[l]=nums1[j];
        //         j=j+1;
        //         l=l+1;
        //     }
        //     else
        //     {
        //         c[l]=nums2[k];                // this was not in place
        //         k=k+1;
        //         l=l+1;
        //     }
        // }
        // if(k==n)
        // {
        //     while(j<m)
        //     {
        //     c[l]=nums1[j];
        //         j=j+1;
        //         l=l+1;
        //     }
        // }
        // else
        // {
        //     while(k<n)
        //     {
        //         c[l]=nums2[k];
        //         k=k+1;
        //         l=l+1;
        //     }
            
        // }
        // for(int i=0;i<(m+n);i++)
        // nums1[i]=c[i];




        // now in place merging(from back)

        int j,k,l;
        j=m-1;
        k=n-1;
        l=m+n-1;
        while(j>=0 && k>=0)
        {
            if(nums1[j]>nums2[k])
            {
                nums1[l]=nums1[j];
                j=j-1;
                l=l-1;
            }
            else
            {
                nums1[l]=nums2[k];
                k=k-1;
                l=l-1;
            }
        }

        if(k>=0)
        {
            while(k>=0)
            {
                nums1[l]=nums2[k];
                k=k-1;
                l=l-1;
            }
            
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;

    sol.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for(int x : nums1)
        cout << x << " ";
    cout << endl;

    return 0;
}
