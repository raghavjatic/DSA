/**
 * Problem: Binary Tree Maximum Path Sum
 * Description: Given the root of a binary tree, return the maximum path sum of any non-empty path. A path can start and end at any node in the tree.
 * Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * Author: Raghav Jatic
 * Date: 25th March 2026
 */

#include <iostream>
#include <vector>
#include <climits>
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
    int maxPathDown(TreeNode* node, int &maxi)
    {
        if(node == NULL)
        return 0;

        int left = max(0, maxPathDown(node->left , maxi)); //0 is written to avoid negative sum from any side
        int right = max(0,maxPathDown(node->right , maxi));

        maxi = max(maxi , left +right + node->val);
        return max(left,right) + node->val; 
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root,maxi);
        return maxi;
    }
};

int main() {
    /*
        Constructing the following binary tree:
                -10
                /  \
               9   20
                   / \
                  15  7
    */

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    int result = obj.maxPathSum(root);

    cout << "Maximum Path Sum: " << result << endl;

    return 0;
}