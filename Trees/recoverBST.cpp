/**
 * Problem: Recover Binary Search Tree
 * Description: Two nodes of a binary search tree are swapped by mistake. Recover the tree without changing its structure.
 * Link: https://leetcode.com/problems/recover-binary-search-tree/
 * Author: Raghav Jatic
 * Date: 8th April 2026
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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;


    void inorder(TreeNode* root)
    {
        if (!root) return;

    inorder(root->left);

        if (prev && root->val < prev->val) {
            if (!first)
                first = prev;
            second = root;
        }
        prev = root;

        inorder(root->right);
    // return;
    }

    void recoverTree(TreeNode* root)
    {
        inorder(root);
        swap(first->val, second->val);
    }
};

void printInorder(TreeNode* node) {
    if (!node) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    /*
        Constructing a BST with swapped nodes:
                3
               / \
              1   4
                 /
                2
        Correct BST should be:
                2
               / \
              1   4
                 /
                3
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    Solution obj;
    obj.recoverTree(root);

    cout << "Inorder after recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}