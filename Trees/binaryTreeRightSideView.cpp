/**
 * Problem: Binary Tree Right Side View
 * Description: Given the root of a binary tree, return the values of the nodes you can see ordered from top to bottom when looking at the tree from the right side.
 * Link: https://leetcode.com/problems/binary-tree-right-side-view/
 * Author: Raghav Jatic
 * Date: 30th March 2026
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

    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;

    if (root == NULL) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {

        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            level.push_back(node->val);

            if (node->left != NULL)
                q.push(node->left);

            if (node->right != NULL)
                q.push(node->right);
        }

        result.push_back(level);
    }

    return result;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        // ans.push_back(root->val);
        vector<vector<int>> result = levelOrder(root);

        for(int i = 0; i < result.size(); i++){
        ans.push_back(result[i][result[i].size() - 1]);
        }

        return ans;
    }
};

int main() {
    /*
        Constructing the following binary tree:
                1
               / \
              2   3
               \   \
                5   4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution obj;
    vector<int> result = obj.rightSideView(root);

    cout << "Right Side View: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}