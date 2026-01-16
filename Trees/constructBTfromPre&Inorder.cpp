/*
 * Problem: Construct Binary Tree from Preorder and Inorder Traversal
 * Description: Given two integer arrays preorder and inorder where preorder is the
 * preorder traversal of a binary tree and inorder is the inorder traversal of the same tree,
 * construct and return the binary tree.
 * Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 *
 * Author: Raghav Jatic
 * Date: 17th January 2026
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
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
    unordered_map<int,int> inorderIndex;
    int preIndex=0;

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd)
    {
        if(inStart>inEnd)
            return NULL;
        
        TreeNode* node = new TreeNode();
        int nodeVal=preorder[preIndex];
        preIndex+=1;
        node->val = nodeVal;

        int idx = inorderIndex[nodeVal];

        node->left = build(preorder, inStart, idx-1 );
        node->right = build(preorder, idx+1, inEnd);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        return build(preorder, 0, inorder.size() - 1);
    }
};

int main() {
    /*
        Preorder: 3 9 20 15 7
        Inorder:  9 3 15 20 7

        Constructed tree:
                3
               / \
              9  20
                 / \
                15  7
    */

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    // Simple inorder print to verify
    // Expected inorder output: 9 3 15 20 7
    function<void(TreeNode*)> inorderPrint = [&](TreeNode* node) {
        if (!node) return;
        inorderPrint(node->left);
        cout << node->val << " ";
        inorderPrint(node->right);
    };

    inorderPrint(root);
    cout << endl;

    return 0;
}