/**
 * Problem: Task Scheduler
 * Description: Given a list of tasks represented by characters and a non-negative integer n representing the cooldown period,
 * determine the least number of time units required to execute all tasks such that identical tasks have at least n intervals between them.
 * Link: https://leetcode.com/problems/task-scheduler/
 * Author: Raghav Jatic
 * Date: 21st March 2026
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    
    // Step 1: Count frequency of each task (A-Z → 26 possible)
    vector<int> freq(26, 0);
    for (char t : tasks) {
        freq[t - 'A']++;   // map 'A'->0, 'B'->1, ...
    }

    // Step 2: Create a max heap (default priority_queue is max heap)
    priority_queue<int> pq;

    // Push all non-zero frequencies into heap
    for (int f : freq) {
        if (f > 0) {
            pq.push(f);   // store counts only
        }
    }

    // Step 3: Queue to handle cooldown
    // pair = {remaining count, time when it can be reused}
    queue<pair<int, int>> q;

    // Time counter (each loop = 1 unit time)
    int time = 0;

    // Step 4: Run until both heap and queue are empty
    while (!pq.empty() || !q.empty()) {

        // Move time forward
        time++;

        // Step 5: If heap has tasks → execute one
        if (!pq.empty()) {
            int cnt = pq.top();  // get most frequent task
            pq.pop();            // remove it from heap

            cnt--;               // execute once → reduce frequency

            // If task still has remaining count
            if (cnt > 0) {
                // Put it in cooldown queue
                // It will be available again at time + n
                q.push({cnt, time + n});
            }
        }

        // Step 6: Check if any task in cooldown is ready
        if (!q.empty() && q.front().second == time) {
            // Bring it back to heap
            pq.push(q.front().first);
            q.pop();
        }
    }

    // Step 7: Total time taken
    return time;
}
};

int main() {
    Solution obj;
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    int result = obj.leastInterval(tasks, n);

    cout << "Least Interval: " << result << endl;

    return 0;
}