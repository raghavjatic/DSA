/**
 * Problem: Implement Queue using Stacks
 * Description: Implement a first-in-first-out (FIFO) queue using only stacks.
 * Link: https://leetcode.com/problems/implement-queue-using-stacks/
 * Author: Raghav Jatic
 * Date: September 2025
 */

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl; // should print 1
    cout << "Pop: " << q.pop() << endl;            // removes 1
    cout << "Front element: " << q.peek() << endl; // should print 2
    cout << "Empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
