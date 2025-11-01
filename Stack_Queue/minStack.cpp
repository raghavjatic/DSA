/*
 * Problem: Min Stack
 * Description: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * Link: https://leetcode.com/problems/min-stack/
 *
 * Author: Raghav Jatic
 * Date: 1st November 2025
 */

#include <iostream>
#include <stack>
#include <climits>   // for INT_MAX
using namespace std;

class MinStack {
    stack<int> st, minSt;

public:
    MinStack() {
        minSt.push(INT_MAX);   // Initialize with a large number
    }

    void push(int val) {
        st.push(val);
        int currentMin = min(minSt.top(), val);
        minSt.push(currentMin);
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout << "Min: " << obj.getMin() << endl; // Output: -3
    obj.pop();
    cout << "Top: " << obj.top() << endl;    // Output: 0
    cout << "Min: " << obj.getMin() << endl; // Output: -2
    return 0;
}
