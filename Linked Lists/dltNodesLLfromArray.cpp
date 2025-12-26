/*
 * Problem: Modify Linked List
 * Description: Given a linked list and an integer array nums, remove all nodes
 * from the linked list whose values are present in nums.
 * Link: https://leetcode.com/problems/modify-linked-list/
 *
 * Author: Raghav Jatic
 * Date: 26th December 2025
 */

#include <iostream>
#include <vector>
#include <unordered_map>
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]++];
        }
        while(head != NULL &&  mp.find(head->val) != mp.end())
        {
            head=head->next;
        }

        ListNode* p=head;

        while(p != NULL && p->next != NULL)
        {
            if(mp.find(p->next->val) != mp.end())
                p->next=p->next->next;
            else
                p=p->next;
        }
        return head;
    }
};

int main() {
    // nums array
    vector<int> nums = {1, 2, 3};

    // Creating linked list: 1 -> 2 -> 4 -> 5 -> 3 -> 6
    ListNode* head = new ListNode(1,
                        new ListNode(2,
                        new ListNode(4,
                        new ListNode(5,
                        new ListNode(3,
                        new ListNode(6))))));

    Solution sol;
    head = sol.modifiedList(nums, head);

    // Print resulting list
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
