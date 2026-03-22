/**
 * Problem: Linked List Random Node
 * Description: Given a singly linked list, return a random node's value from the linked list.
 * Each node must have the same probability of being chosen.
 * Link: https://leetcode.com/problems/linked-list-random-node/
 * Author: Raghav Jatic
 * Date: 22nd March 2026
 */

#include <iostream>
#include <vector>
#include <cstdlib>
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
    ListNode* head;
    int n;

    Solution(ListNode* head) {
        this->head = head;
        n = 0;

        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
    }
    
    int getRandom() {
        int idx = rand() % n;

        ListNode* temp = head;
        while (idx) {
            temp = temp->next;
            idx--;
        }

        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main() {
    // Creating a sample linked list: 10 -> 20 -> 30 -> 40
    ListNode* head = new ListNode(10,
                        new ListNode(20,
                        new ListNode(30,
                        new ListNode(40))));

    Solution obj(head);

    cout << "Random Node Value: " << obj.getRandom() << endl;

    return 0;
}