/*
 * Problem: Fizz Buzz
 * Description: Given an integer n, return a string array answer (1-indexed) where:
 * - answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
 * - answer[i] == "Fizz" if i is divisible by 3.
 * - answer[i] == "Buzz" if i is divisible by 5.
 * - answer[i] == i (as a string) if none of the above conditions are true.
 * Link: https://leetcode.com/problems/fizz-buzz/
 *
 * Author: Raghav Jatic
 * Date: 21st December 2025
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer(n,"");
        int j;
        for(int i=0;i<n;i++)
        {
            j=i+1;
            if(j%3 == 0 && j%5 == 0)
            answer[i]="FizzBuzz";
            else if(j%3 == 0)
            answer[i]="Fizz";
            else if(j%5 == 0)
            answer[i]="Buzz";
            else
            answer[i]=to_string(j);
        }
        return answer;
    }
};

int main() {
    Solution sol;

    int n = 15;
    vector<string> res = sol.fizzBuzz(n);

    for (string &s : res) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
