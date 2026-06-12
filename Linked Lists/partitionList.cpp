/**
 * Problem: Partition List
 * Description: Given the head of a linked list and a value x, partition it such that all nodes less than x
 * come before nodes greater than or equal to x, while preserving the original relative order.
 * Link: https://leetcode.com/problems/partition-list/
 * Author: Raghav Jatic
 * Date: 30th March 2026
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head2 = new ListNode(0); // dummy head for < x
        ListNode* p = head2;

        ListNode* head3 = new ListNode(0); // dummy head for >= x
        ListNode* q = head3;

        while (head != NULL)
        {
            ListNode* temp = head;
            head = head->next;

            temp->next = NULL; //(break old link)

            if (temp->val < x)
            {
                p->next = temp;
                p = p->next;
            } 
            
            else
            {
                q->next = temp;
                q = q->next;
            }
        }

        // connect both lists
        p->next = head3->next;

        return head2->next;
    }
};

int main() {
    Solution obj;

    // Creating sample linked list: 1 -> 4 -> 3 -> 2 -> 5 -> 2
    ListNode* head = new ListNode(1,
                        new ListNode(4,
                        new ListNode(3,
                        new ListNode(2,
                        new ListNode(5,
                        new ListNode(2))))));

    int x = 3;

    ListNode* result = obj.partition(head, x);

    cout << "Partitioned List: ";
    while(result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}