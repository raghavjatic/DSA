/*
 * Problem: Binary Tree Inorder Traversal
 * Description: Given the root of a binary tree, return the inorder traversal
 * of its nodes' values.
 * Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
 *
 * Author: Raghav Jatic
 * Date: January 2026
 */

#include <iostream>
#include <vector>
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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)
            return ans;
        else
        {
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
        }
        return ans;
    }
};

int main() {
    /*
        Constructing binary tree:
                1
                 \
                  2
                 /
                3
        Inorder traversal: 1 3 2
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
