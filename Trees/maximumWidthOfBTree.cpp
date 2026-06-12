/**
 * Problem: Maximum Width of Binary Tree
 * Description: Given the root of a binary tree, return the maximum width of the tree. The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), including null nodes in between.
 * Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
 * Author: Raghav Jatic
 * Date: 7th April 2026
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) 
        return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while (!q.empty()) 
        {
            int size = q.size();
            long long minIndex = q.front().second; // to avoid overflow

            long long first, last;

            for (int i = 0; i < size; i++) 
            {
                pair<TreeNode*, long long> temp = q.front();
TreeNode* node = temp.first;
long long index = temp.second;
                q.pop();

                index -= minIndex; // normalize

                if (i == 0) 
                first = index;
                if (i == size - 1) 
                last = index;

                if (node->left)
                    q.push({node->left, 2 * index});
                if (node->right)
                    q.push({node->right, 2 * index + 1});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};

int main() {
    /*
        Constructing the following binary tree:
                1
               / \
              3   2
             /     \
            5       9
           /         \
          6           7
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Solution obj;
    int result = obj.widthOfBinaryTree(root);

    cout << "Maximum Width of Binary Tree: " << result << endl;

    return 0;
}