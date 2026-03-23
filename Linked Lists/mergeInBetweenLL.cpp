/**
 * Problem: Merge In Between Linked Lists
 * Description: You are given two linked lists list1 and list2 of sizes n and m respectively.
 * Remove list1's nodes from index a to b and put list2 in their place.
 * The indices are 0-indexed.
 * Link: https://leetcode.com/problems/merge-in-between-linked-lists/
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;
        int c = b - a;
        int j = a;
        a = a - 1;

        while(a--) {
            list1 = list1->next;
        }

        ListNode* temp = list1;
        

        for(int i = 0; i <= c + 1; i++) {
            temp = temp->next;
        }

        list1->next = list2;

        while(list2->next != NULL) {
            list2 = list2->next;
        }

        list2->next = temp;

        return head;
    }
};

int main() {
    Solution obj;

    // list1: 0 -> 1 -> 2 -> 3 -> 4 -> 5
    ListNode* list1 = new ListNode(0,
                        new ListNode(1,
                        new ListNode(2,
                        new ListNode(3,
                        new ListNode(4,
                        new ListNode(5))))));

    // list2: 1000000 -> 1000001 -> 1000002
    ListNode* list2 = new ListNode(1000000,
                        new ListNode(1000001,
                        new ListNode(1000002)));

    int a = 3, b = 4;

    ListNode* result = obj.mergeInBetween(list1, a, b, list2);

    cout << "Merged List: ";
    while(result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}