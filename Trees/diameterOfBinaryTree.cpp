/*
 * Problem: Diameter of Binary Tree
 * Description: Given the root of a binary tree, return the length of the diameter
 * of the tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the root.
 * Link: https://leetcode.com/problems/diameter-of-binary-tree/
 *
 * Author: Raghav Jatic
 * Date: 14th February 2026
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
    int maxi=0;

    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int lh = height(root -> left);
        int rh = height(root -> right);

        maxi = max(maxi , lh+rh);

        return 1+max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxi;
    }
};

int main() {
    /*
        Constructing binary tree:
                1
               / \
              2   3
             / \
            4   5

        Diameter = 3
    */

    TreeNode* root = new TreeNode(1,
                        new TreeNode(2,
                            new TreeNode(4),
                            new TreeNode(5)),
                        new TreeNode(3));

    Solution sol;
    cout << sol.diameterOfBinaryTree(root) << endl; // Expected: 3

    return 0;
}
