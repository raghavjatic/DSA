/**
 * Problem: Merge k Sorted Lists
 * Description: You are given an array of k linked-lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 * Link: https://leetcode.com/problems/merge-k-sorted-lists/
 * Author: Raghav Jatic
 * Date: 21st March 2026
 */

#include <iostream>
#include <vector>
#include <queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i=0;i<lists.size(); i++)
        {
            ListNode* temp = lists[i];
            while(temp!= NULL)
            {
                heap.push(temp->val);
                temp = temp-> next;
            }
        }

        ListNode* temp = new ListNode(0);
        ListNode* start = temp;
        while(!heap.empty())
        {
            start->next = new ListNode(heap.top());
            heap.pop();
            start=start->next;
        }

        return temp->next;
    }
};

int main() {
    Solution obj;

    // Creating sample linked lists:
    // List 1: 1 -> 4 -> 5
    // List 2: 1 -> 3 -> 4
    // List 3: 2 -> 6

    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));

    vector<ListNode*> lists = {l1, l2, l3};

    ListNode* result = obj.mergeKLists(lists);

    cout << "Merged List: ";
    while(result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}