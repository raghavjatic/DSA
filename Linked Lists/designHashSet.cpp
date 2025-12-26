/*
 * Problem: Design HashSet
 * Description: Design a HashSet without using any built-in hash table libraries.
 * Note: Although this implementation works, LeetCode expects a solution using
 * hashing with buckets. This version uses a singly linked list.
 * Link: https://leetcode.com/problems/design-hashset/
 *
 * Author: Raghav Jatic
 * Date: 23rd December 2025
 */

#include <iostream>
using namespace std;

//Although this code works, this is not what LeetCode expects in this question.
//It expects hashing with buckets. This is only good for initial Linked List understanding.

class MyHashSet {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* head;
    ListNode* p;

public:
    MyHashSet() {
        head = NULL;
        p = NULL;
    }

    void add(int key) {
        if (contains(key))  // no duplicates
            return;

        if (head == NULL) {
            head = new ListNode(key);
            p = head;
        } else {
            ListNode* temp = new ListNode(key);
            p->next = temp;
            p = temp;
        }
    }

    void remove(int key) {
        // Case 1: empty list
        if (head == NULL)
            return;

        // Case 2: key is at head
        if (head->val == key) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Case 3: key is after head
        ListNode* q = head;
        while (q->next != NULL) {
            if (q->next->val == key) {
                ListNode* r = q->next;
                q->next = q->next->next;

                if (r == p)
                    p = q;

                delete r;
                return;
            }
            q = q->next;
        }
    }

    bool contains(int key) {
        ListNode* k = head;
        while (k != NULL) {
            if (k->val == key)
                return true;
            k = k->next;
        }
        return false;
    }
};

int main() {
    MyHashSet* obj = new MyHashSet();

    obj->add(1);
    obj->add(2);

    cout << obj->contains(1) << endl; // Expected: 1 (true)
    cout << obj->contains(3) << endl; // Expected: 0 (false)

    obj->add(2);
    cout << obj->contains(2) << endl; // Expected: 1 (true)

    obj->remove(2);
    cout << obj->contains(2) << endl; // Expected: 0 (false)

    return 0;
}
