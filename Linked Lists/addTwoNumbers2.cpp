/*
 * Problem: Add Two Numbers II
 * Description: Given two non-empty linked lists representing two non-negative integers,
 * where the most significant digit comes first, add the two numbers and return the sum
 * as a linked list.
 * Link: https://leetcode.com/problems/add-two-numbers-ii/
 *
 * Author: Raghav Jatic
 * Date: 27th December 2025
 */

#include <iostream>
#include <stack>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        ListNode* a=l1;
        ListNode* b=l2;
        while(a!=NULL)
        {
            st1.push(a->val);
            a=a->next;
        }
        while(b!=NULL)
        {
            st2.push(b->val);
            b=b->next;
        }
        int sum=0;
        int carry=0;
        ListNode* l3 = new ListNode();
        ListNode* p = new ListNode();
        p=NULL;
        while(!(st1.empty()) && !(st2.empty()))
        {
            sum=st1.top() + st2.top() + carry;
            carry=0;
            st1.pop();
            st2.pop();
            if(sum>9)
            {
                sum=sum%10;
                carry=1;
            }
            ListNode* temp=new ListNode(sum);
            temp->next=p;
            p=temp;
        }

        while(!(st1.empty()))
        {
            sum=st1.top() + carry;
            carry=0;
            st1.pop();
            if(sum>9)
            {
                sum=sum%10;
                carry=1;
            }
            ListNode* temp=new ListNode(sum);
            temp->next=p;
            p=temp;
        }

        while(!(st2.empty()))
        {
            sum=st2.top() + carry;
            carry=0;
            st2.pop();
            if(sum>9)
            {
                sum=sum%10;
                carry=1;
            }
            ListNode* temp=new ListNode(sum);
            temp->next=p;
            p=temp;
        }
        
        if(carry)
        {
            ListNode* temp=new ListNode(1);
            temp->next=p;
            p=temp;
            carry =0;
        }

        return p;
    }
};

int main() {
    // l1 = 7 -> 2 -> 4 -> 3
    ListNode* l1 = new ListNode(7,
                        new ListNode(2,
                        new ListNode(4,
                        new ListNode(3))));

    // l2 = 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5,
                        new ListNode(6,
                        new ListNode(4)));

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    // Expected: 7 -> 8 -> 0 -> 7
    ListNode* temp = result;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
