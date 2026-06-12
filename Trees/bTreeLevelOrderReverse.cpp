/**
 * Problem: Binary Tree Level Order Traversal II
 * Description: Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values.
 * Link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};

class Solution {
public:

    vector<vector<int>> ans1;
    void levelOrder(TreeNode* root) {
        if (root == NULL)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> v1;

            while (size--) 
            {
                TreeNode* curr = q.front();
                q.pop();

                v1.push_back(curr->val);

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            ans1.push_back(v1);
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        levelOrder(root);
        vector<vector<int>> ans;
        for(int i = ans1.size()-1; i>=0; i--)
        {
            ans.push_back(ans1[i]);
        }
        return ans;
    }
};

//more optimized solution
// class Solution {
// public:
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {

//         vector<vector<int>> ans;

//         if (!root) return ans;

//         queue<TreeNode*> q;
//         q.push(root);

//         while (!q.empty()) {
//             int size = q.size();
//             vector<int> level;

//             while (size--) {
//                 TreeNode* curr = q.front();
//                 q.pop();

//                 level.push_back(curr->val);

//                 if (curr->left) q.push(curr->left);
//                 if (curr->right) q.push(curr->right);
//             }

//             ans.insert(ans.begin(), level); // key change
//         }

//         return ans;
//     }
// };

int main() {
    /*
        Constructing the following binary tree:
                3
               / \
              9   20
                 /  \
                15   7
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<vector<int>> result = obj.levelOrderBottom(root);

    cout << "Level Order Bottom Traversal:\n";
    for(auto &level : result) {
        for(int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}