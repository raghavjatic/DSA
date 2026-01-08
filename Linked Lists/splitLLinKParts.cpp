/*
 * Problem: Split Linked List in Parts
 * Description: Given the head of a singly linked list and an integer k,
 * split the linked list into k consecutive linked list parts.
 * Link: https://leetcode.com/problems/split-linked-list-in-parts/
 *
 * Author: Raghav Jatic
 * Date: 8th January 2026
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0;
        ListNode* p = head;
        vector<ListNode*> ans;
        while (p != NULL) {
            cnt = cnt + 1;
            p = p->next;
        }
        int rem = cnt % k;

        if (head == NULL) {
            while (k != 0) {
                ans.push_back(NULL);
                k = k - 1;
            }
            return ans;
        }

        // for equal parts distribution:
        if (rem == 0) {
            int length = cnt / k;
            p = head;
            ListNode* q = p;
            while (p != NULL) {
                ans.push_back(p);
                while (length != 0) {
                    length = length - 1;
                    q = p;
                    p = p->next;
                }
                q->next = NULL;
                length = cnt / k;
            }
            return ans;
        }

        // for k greater than length
        else if (k > cnt) {
            int length = k;
            p = head;
            ListNode* q;
            q = p;
            while (k != 0) {
                if (p != NULL) {
                    q = p;
                    ans.push_back(q);
                    p = p->next;
                    q->next = NULL;
                } else
                    ans.push_back(NULL);
                k = k - 1;
            }
            return ans;
        }

        // for unequal parts distribution:
        p = head;
        ListNode* q = p;
        int length = cnt / k;

        while (k != 0) {
            ans.push_back(p);

            int currLen = length;

            if (rem > 0) {
                currLen = currLen + 1;
                rem = rem - 1;
            }

            while (currLen != 0) {
                q = p;
                p = p->next;
                currLen = currLen - 1;
            }

            if (q != NULL)
                q->next = NULL;

            k = k - 1;
        }

        return ans;
    }
};

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    ListNode* head = new ListNode(1,
                        new ListNode(2,
                        new ListNode(3,
                        new ListNode(4,
                        new ListNode(5,
                        new ListNode(6,
                        new ListNode(7)))))));

    int k = 3;
    Solution sol;
    vector<ListNode*> parts = sol.splitListToParts(head, k);

    // Print each part
    for (int i = 0; i < parts.size(); i++) {
        ListNode* temp = parts[i];
        cout << "Part " << i + 1 << ": ";
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}
