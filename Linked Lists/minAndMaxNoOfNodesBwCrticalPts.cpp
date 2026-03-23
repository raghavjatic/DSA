/**
 * Problem: Find the Minimum and Maximum Number of Nodes Between Critical Points
 * Description: A critical point in a linked list is defined as either a local maxima or a local minima.
 * Return an array of length 2 containing the minimum and maximum distance between any two distinct critical points.
 * If there are fewer than two critical points, return {-1, -1}.
 * Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
 * Author: Raghav Jatic
 * Date: 23rd March 2026
 */

#include <iostream>
#include <vector>
#include <climits>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        int minN, maxN;
        maxN = -1;
        minN = INT_MAX;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;

        int nodeNo = 1;

        int first = -1, last = -1;

        while(next) {
            if((prev && next) &&
               ((curr->val < prev->val && curr->val < next->val) ||   // minima
                (curr->val > prev->val && curr->val > next->val)))    // maxima
            {
                if(first == -1) {
                    first = nodeNo;
                }
                else {
                    minN = min(minN, nodeNo - last);
                }
                last = nodeNo;
                maxN = last - first;
            }

            prev = curr;
            curr = next;
            next = next->next;
            nodeNo += 1;
        }

        if(maxN == -1 || minN == INT_MAX) return {-1, -1};

        ans = {minN, maxN};
        return ans;
    }
};

int main() {
    Solution obj;

    // Creating sample linked list: 5 -> 3 -> 1 -> 2 -> 5 -> 1 -> 2
    ListNode* head = new ListNode(5,
                        new ListNode(3,
                        new ListNode(1,
                        new ListNode(2,
                        new ListNode(5,
                        new ListNode(1,
                        new ListNode(2)))))));

    vector<int> result = obj.nodesBetweenCriticalPoints(head);

    cout << "Min Distance: " << result[0] << ", Max Distance: " << result[1] << endl;

    return 0;
}