/*
 * Problem: Same Tree
 * Description: Given the roots of two binary trees p and q, write a function to
 * check if they are the same or not.
 * Two binary trees are considered the same if they are structurally identical,
 * and the nodes have the same value.
 * Link: https://leetcode.com/problems/same-tree/
 *
 * Author: Raghav Jatic
 * Date: 11th January 2026
 */

#include <iostream>
#include <vector>
#include <string>
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

    void preorder(TreeNode* root, vector<string>& ans) {
        if (!root)
        {
            ans.push_back("NULL");
            return;
        }

        ans.push_back(to_string(root->val));
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<string> tree1;
        vector<string> tree2;
        preorder(p,tree1);
        preorder(q,tree2);
        if(tree1.size() != tree2.size())
            return false;
        else
        {
            for(int i=0;i<tree1.size();i++)
            {
                if(tree1[i] != tree2[i])
                    return false;
            }
        }
        return true;
    }
};

int main() {
    /*
        Tree 1:
              1
             / \
            2   3

        Tree 2:
              1
             / \
            2   3
    */

    TreeNode* p = new TreeNode(1,
                        new TreeNode(2),
                        new TreeNode(3));

    TreeNode* q = new TreeNode(1,
                        new TreeNode(2),
                        new TreeNode(3));

    Solution sol;
    cout << sol.isSameTree(p, q) << endl; // Expected: 1 (true)

    return 0;
}
