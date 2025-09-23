/**
 * Problem: Implement Stack using Queues
 * Description: Implement a last-in-first-out (LIFO) stack using only queues.
 * Link: https://leetcode.com/problems/implement-stack-using-queues/
 * Author: Raghav Jatic
 * Date: 24th September 2025
 */

#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        // rotate the queue to make it LIFO
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // should print 30
    cout << "Pop: " << st.pop() << endl;         // should remove 30
    cout << "Top element: " << st.top() << endl; // should print 20
    cout << "Empty? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}
