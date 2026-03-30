/**
 * Problem: Populating Next Right Pointers in Each Node
 * Description: Given a perfect binary tree, populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 * Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * Author: Raghav Jatic
 * Date: 31st March 2026
 */

#include <iostream>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) 
        return NULL;

        Node* level = root;

        // Traverse level by level
        while (level->left != NULL) 
        {
            Node* curr = level;

            // Traverse nodes in current level
            while (curr != NULL) 
            {

                // Connect left child to right child
                curr->left->next = curr->right;

                // Connect right child to next node's left child
                if (curr->next != NULL) 
                {
                    curr->right->next = curr->next->left;
                }

                // Move to next node in same level
                curr = curr->next;
            }

            // Move to next level
            level = level->left;
        }

        return root;
    }
};

int main() {
    /*
        Constructing the following perfect binary tree:
                1
               / \
              2   3
             / \ / \
            4  5 6  7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    obj.connect(root);

    // Print next pointers level-wise
    Node* level = root;
    while(level != NULL) {
        Node* curr = level;
        while(curr != NULL) {
            cout << curr->val << "->";
            if(curr->next)
                cout << curr->next->val << " ";
            else
                cout << "NULL ";
            curr = curr->next;
        }
        cout << endl;
        level = level->left;
    }

    return 0;
}