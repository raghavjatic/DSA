/*
 * Problem: Symmetric Tree
 * Description: Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 * Link: https://leetcode.com/problems/symmetric-tree/
 *
 * Author: Raghav Jatic
 * Date: 14th January 2026
 */

#include <iostream>
#include <queue>
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        queue<TreeNode*> q;
        queue<TreeNode*> p;
        q.push(l);
        p.push(r);
        while(!q.empty() && !p.empty())
        {
            l=q.front();
            r=p.front();
            q.pop();
            p.pop();
            if(!l && !r) continue;
            if(!l || !r)
                return false;
            if(l->val != r->val)
                return false;
            q.push(l->left);
            q.push(l->right);
            p.push(r->right);
            p.push(r->left);
        }
        return true;
    }
};

int main() {
    /*
        Constructing binary tree:
                1
               / \
              2   2
             / \ / \
            3  4 4  3
    */

    TreeNode* root = new TreeNode(1,
                        new TreeNode(2,
                            new TreeNode(3),
                            new TreeNode(4)),
                        new TreeNode(2,
                            new TreeNode(4),
                            new TreeNode(3)));

    Solution sol;
    cout << sol.isSymmetric(root) << endl; // Expected: 1 (true)

    return 0;
}
