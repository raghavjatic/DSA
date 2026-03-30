/**
 * Problem: Flatten Binary Tree to Linked List
 * Description: Given the root of a binary tree, flatten the tree into a linked list in-place following preorder traversal.
 * Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * Author: Raghav Jatic
 * Date: 30th March 2026
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
    TreeNode* prev = NULL;

    void preorder(TreeNode* root) {
        if (root == NULL) return;

        if (prev) 
        {
            prev->right = root;
            prev->left = NULL;
        }

        prev = root;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        preorder(left);
        preorder(right);
    }

    void flatten(TreeNode* root) {
        preorder(root);
    }
};

int main() {
    /*
        Constructing the following binary tree:
                1
               / \
              2   5
             / \   \
            3   4   6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution obj;
    obj.flatten(root);

    cout << "Flattened Tree (Right pointers): ";
    TreeNode* curr = root;
    while(curr != NULL) {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;

    return 0;
}