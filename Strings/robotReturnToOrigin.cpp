/*
 * Problem: Robot Return to Origin
 * Description: There is a robot starting at the origin (0, 0). Given a sequence of
 * moves, determine if the robot returns to the origin after completing the moves.
 * Link: https://leetcode.com/problems/robot-return-to-origin/
 *
 * Author: Raghav Jatic
 * Date: 24th December 2025
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int len=moves.size();
        int i=0;
        int sum1,sum2;
        sum1=sum2=0;
        while(i<len)
        {
            if(moves[i]=='U')
                sum1=sum1+1;
            else if(moves[i]=='D')
                sum1=sum1-1;
            else if(moves[i]=='R')
                sum2=sum2+1;
            else if(moves[i]=='L')
                sum2=sum2-1;

            i=i+1;
        }
        if(sum1 == 0 && sum2 == 0)
            return true;
        return false;
    }
};

int main() {
    Solution sol;

    cout << sol.judgeCircle("UD") << endl;     // Expected: 1 (true)
    cout << sol.judgeCircle("LL") << endl;     // Expected: 0 (false)
    cout << sol.judgeCircle("URDL") << endl;   // Expected: 1 (true)

    return 0;
}
