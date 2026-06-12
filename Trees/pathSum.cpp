/**
 * Problem: Path Sum
 * Description: Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values equals targetSum.
 * Link: https://leetcode.com/problems/path-sum/
 * Author: Raghav Jatic
 * Date: 8th April 2026
 */

#include <iostream>
#include <vector>
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
    bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;

    queue<pair<TreeNode*, int>> q;
    q.push({root, root->val});

    while (!q.empty()) {
        pair<TreeNode*, int> temp = q.front();
        TreeNode* node = temp.first;
        int sum = temp.second;
        q.pop();

        if (!node->left && !node->right && sum == targetSum)
            return true;

        if (node->left)
            q.push({node->left, sum + node->left->val});
        if (node->right)
            q.push({node->right, sum + node->right->val});
    }

    return false;
}
};

int main() {
    /*
        Constructing the following binary tree:
                5
               / \
              4   8
             /   / \
            11  13  4
           /  \       \
          7    2       1
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution obj;
    int targetSum = 22;

    bool result = obj.hasPathSum(root, targetSum);

    if(result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}