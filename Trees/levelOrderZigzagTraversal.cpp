/*
 * Problem: Binary Tree Zigzag Level Order Traversal
 * Description: Given the root of a binary tree, return the zigzag level order
 * traversal of its nodes' values (i.e., left to right, then right to left for
 * the next level and alternate between).
 * Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 *
 * Author: Raghav Jatic
 * Date: 11th January 2026
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size(); // current level size
            vector<int> level;

            for(int i=0;i<size;i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(level);
        }

        int size = ans.size();
        for(int i=1;i<size;i=i+2)
        {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};

int main() {
    /*
        Constructing binary tree:
                3
               / \
              9  20
                 / \
                15  7

        Zigzag level order traversal:
        [3]
        [20, 9]
        [15, 7]
    */

    TreeNode* root = new TreeNode(3,
                        new TreeNode(9),
                        new TreeNode(20,
                            new TreeNode(15),
                            new TreeNode(7)));

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    // Print result
    for (auto &level : result) {
        for (int x : level) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
