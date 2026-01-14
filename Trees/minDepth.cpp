/*
 * Problem: Minimum Depth of Binary Tree
 * Description: Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path
 * from the root node down to the nearest leaf node.
 * Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        // If one child is missing, go through the other
        if (!root->left)
            return 1 + minDepth(root->right);

        if (!root->right)
            return 1 + minDepth(root->left);

        // Both children exist
        return 1 + min(minDepth(root->left), minDepth(root->right));
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

        Minimum depth = 2 (3 -> 9)
    */

    TreeNode* root = new TreeNode(3,
                        new TreeNode(9),
                        new TreeNode(20,
                            new TreeNode(15),
                            new TreeNode(7)));

    Solution sol;
    cout << sol.minDepth(root) << endl; // Expected: 2

    return 0;
}
