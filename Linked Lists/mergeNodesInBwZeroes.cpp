/**
 * Problem: Merge Nodes in Between Zeros
 * Description: You are given the head of a linked list, which contains a series of integers separated by 0s.
 * The beginning and end of the linked list will have Node.val == 0.
 * For every two consecutive 0s, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes.
 * Return the head of the modified linked list.
 * Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/
 * Author: Raghav Jatic
 * Date: 23rd March 2026
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;   // skip first 0
        ListNode* temp = head;         // to build answer
        
        int sum = 0;

        while(curr) {
            if(curr->val == 0) {
                temp->next = new ListNode(sum);
                temp = temp->next;
                sum = 0;
            }
            else {
                sum += curr->val;
            }
            curr = curr->next;
        }

        temp->next = NULL;
        return head->next;
    }
};

int main() {
    Solution obj;

    // Creating sample linked list: 0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0
    ListNode* head = new ListNode(0,
                        new ListNode(3,
                        new ListNode(1,
                        new ListNode(0,
                        new ListNode(4,
                        new ListNode(5,
                        new ListNode(2,
                        new ListNode(0))))))));

    ListNode* result = obj.mergeNodes(head);

    cout << "Merged List: ";
    while(result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}