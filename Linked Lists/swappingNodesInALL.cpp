/**
 * Problem: Swapping Nodes in a Linked List
 * Description: You are given the head of a linked list, and an integer k.
 * Return the head of the linked list after swapping the values of the kth node from the beginning
 * and the kth node from the end (the list is 1-indexed).
 * Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
 * Author: Raghav Jatic
 * Date: 22nd March 2026
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1= head;
        ListNode* temp2=head;
        for(int i=1;i<k;i++)
        {
            temp1=temp1->next;
        }
        ListNode* temp3=temp1;

        int a= temp1->val;

        while(temp1->next != NULL)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp3->val = temp2->val;
        temp2->val = a;

        return head;
    }
};

int main() {
    Solution obj;

    // Creating sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1,
                        new ListNode(2,
                        new ListNode(3,
                        new ListNode(4,
                        new ListNode(5)))));

    int k = 2;

    ListNode* result = obj.swapNodes(head, k);

    cout << "Updated List: ";
    while(result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}