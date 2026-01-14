/*
 * Problem: Maximum Depth of Binary Tree
 * Description: Given the root of a binary tree, return its maximum depth.
 * The maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 * Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 *
 * Author: Raghav Jatic
 * Date: 15th January 2026
 */

#include <iostream>
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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int left = maxDepth(root->left);
        int right= maxDepth(root->right);

        return 1 + max(left,right);
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

        Maximum depth = 3
    */

    TreeNode* root = new TreeNode(3,
                        new TreeNode(9),
                        new TreeNode(20,
                            new TreeNode(15),
                            new TreeNode(7)));

    Solution sol;
    cout << sol.maxDepth(root) << endl; // Expected: 3

    return 0;
}
