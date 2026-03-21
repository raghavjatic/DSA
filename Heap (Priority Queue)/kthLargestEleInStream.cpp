/**
 * Problem: Kth Largest Element in a Stream
 * Description: Design a class to find the kth largest element in a stream. 
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * Implement KthLargest class with a constructor and an add method.
 * Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
 * Author: Raghav Jatic
 * Date: 21st March 2026
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k) {
                pq.pop();  // remove smallest
            }
        }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > k) {
            pq.pop();
        }

        return pq.top(); // kth largest (the smalest of total k elements on the top of a min heap)
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;

    KthLargest obj(k, nums);

    cout << obj.add(3) << endl;   // returns 4
    cout << obj.add(5) << endl;   // returns 5
    cout << obj.add(10) << endl;  // returns 5
    cout << obj.add(9) << endl;   // returns 8
    cout << obj.add(4) << endl;   // returns 8

    return 0;
}