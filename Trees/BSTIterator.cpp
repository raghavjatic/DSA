/**
 * Problem: Binary Search Tree Iterator
 * Description: Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST).
 * The iterator should return the next smallest number in the BST.
 * Link: https://leetcode.com/problems/binary-search-tree-iterator/
 * Author: Raghav Jatic
 * Date: 21st March 2026
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

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        
    }
    
    int next() {
        
    }
    
    bool hasNext() {
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    // Creating a sample BST:
    //        7
    //       / \
    //      3   15
    //         /  \
    //        9    20

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15, new TreeNode(9), new TreeNode(20));

    BSTIterator* obj = new BSTIterator(root);

    // Since methods are not implemented, this is just structure demonstration
    // Uncomment when logic is implemented
    // cout << obj->next() << endl;
    // cout << obj->hasNext() << endl;

    return 0;
}