/*
 * Problem: Search in a Binary Search Tree
 * Description: Given the root of a binary search tree (BST) and an integer val,
 * find the node in the BST that the node's value equals val and return the subtree
 * rooted with that node. If such a node does not exist, return NULL.
 * Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
 *
 * Author: Raghav Jatic
 * Date: 13th January 2026
 */

#include <iostream>
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL) {
            if (root->val == val)
                return root;
            else if (val < root->val)
                root = root->left;
            else
                root = root->right;
        }
        return NULL;
    }
};

int main() {
    /*
        Constructing BST:
                4
               / \
              2   7
             / \
            1   3
    */

    TreeNode* root = new TreeNode(4,
                        new TreeNode(2,
                            new TreeNode(1),
                            new TreeNode(3)),
                        new TreeNode(7));

    Solution sol;
    TreeNode* result = sol.searchBST(root, 2);

    if (result != nullptr) {
        cout << "Found node with value: " << result->val << endl;
    } else {
        cout << "Value not found in BST" << endl;
    }

    return 0;
}
