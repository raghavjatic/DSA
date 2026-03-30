/**
 * Problem: The K Weakest Rows in a Matrix
 * Description: You are given an m x n binary matrix mat of 1's (soldiers) and 0's (civilians).
 * The soldiers are positioned in front of the civilians in each row.
 * A row i is weaker than a row j if one of the following is true:
 * - The number of soldiers in row i is less than the number of soldiers in row j.
 * - Both rows have the same number of soldiers and i < j.
 * Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
 * Link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
 * Author: Raghav Jatic
 * Date: 23rd March 2026
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countOnes(vector<vector<int>>& mat, int i )
    {
        //binary method because ones are contained in the starting only 
        int l = 0, r = mat[0].size() - 1;

        while(l <= r) {
            int mid = (l + r) / 2;
            if(mat[i][mid] == 1)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0;i< mat.size();i++)
        {
            int ones= countOnes(mat,i);
            pq.push({ones,i});
        }

        vector<int> ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> mat = {
        {1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}
    };

    int k = 3;

    vector<int> result = obj.kWeakestRows(mat, k);

    cout << "K Weakest Rows: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}