/*
 * Problem: Balanced Binary Tree
 * Description: Given a binary tree, determine if it is height-balanced.
 * A height-balanced binary tree is defined as a binary tree in which the depth
 * of the two subtrees of every node never differs by more than one.
 * Link: https://leetcode.com/problems/balanced-binary-tree/
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
    int height(TreeNode* root) {
        if (!root) return 0;

        int lh = height(root->left);
        if (lh == -1) return -1;

        int rh = height(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;

        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
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
        Balanced tree
    */

    TreeNode* root = new TreeNode(3,
                        new TreeNode(9),
                        new TreeNode(20,
                            new TreeNode(15),
                            new TreeNode(7)));

    Solution sol;
    cout << sol.isBalanced(root) << endl; // Expected: 1 (true)

    return 0;
}
