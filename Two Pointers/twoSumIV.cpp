/*
 * Problem: Two Sum IV - Input is a BST
 * Description: Determine if there exist two elements in the BST such that their sum equals k.
 * Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
 * Author: Raghav Jatic
 * Date: 9th June 2026
 */



//What would a true two-pointer approach be?

// Since the tree is a BST, you can exploit its sorted order.

// Perform an inorder traversal → gives values in ascending order.
// Then either:
// Store them in a vector and run two pointers on the vector.
// Or use two BST iterators:
// one iterator gives the next smallest value,
// another gives the next largest value.


#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        if (root == NULL)
            return false;

        queue<TreeNode*> q;
        q.push(root);

        unordered_map<int, int> mp;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            auto it = mp.find(k - curr->val);

            if (it != mp.end()) {
                return true;
            }

            mp[curr->val] += 1;

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        return false;
    }
};

int main() {
    /*
            5
           / \
          3   6
         / \   \
        2   4   7
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);

    Solution sol;

    int k = 9;

    cout << boolalpha;
    cout << "Target Sum Exists: " << sol.findTarget(root, k) << endl;

    return 0;
}