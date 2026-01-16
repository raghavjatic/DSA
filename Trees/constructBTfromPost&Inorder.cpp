/*
 * Problem: Construct Binary Tree from Inorder and Postorder Traversal
 * Description: Given two integer arrays inorder and postorder where inorder is the
 * inorder traversal of a binary tree and postorder is the postorder traversal of the same tree,
 * construct and return the binary tree.
 * Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    int postIndex;

    TreeNode* build(vector<int>& postorder, int inStart, int inEnd)
    {
        if(inStart>inEnd)
            return NULL;
        
        TreeNode* node = new TreeNode();
        int nodeVal=postorder[postIndex];
        postIndex-=1;
        node->val = nodeVal;

        int idx = inorderIndex[nodeVal];

        node->right = build(postorder, idx+1, inEnd);
        node->left = build(postorder, inStart, idx-1 );

        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        postIndex = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        return build(postorder, 0, inorder.size() - 1);
    }
};

int main() {
    /*
        Inorder:   9 3 15 20 7
        Postorder: 9 15 7 20 3

        Constructed tree:
                3
               / \
              9  20
                 / \
                15  7
    */

    vector<int> inorder  = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

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
