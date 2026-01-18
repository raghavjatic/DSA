/*
 * Problem: Binary Tree Preorder Traversal
 * Description: Given the root of a binary tree, return the preorder traversal
 * of its nodes' values.
 * Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
 *
 * Author: Raghav Jatic
 * Date: 18th January 2026
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
    void dfs(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        ans.push_back(root->val);
        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
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

        Preorder traversal: 1 2 3
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
