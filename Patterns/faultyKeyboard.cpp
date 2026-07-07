/*
 * Problem: Faulty Keyboard
 * Description: Simulate the faulty keyboard where typing 'i' reverses the
 *              current string instead of being added to it.
 * Link: https://leetcode.com/problems/faulty-keyboard/
 * Author: Raghav Jatic
 * Date: 1st July 2026
 * Pattern type: String Manipulation
 */

#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    string finalString(string s) {

        deque<char> dq;
        bool rev = false;

        for(char ch : s)
        {
            if(ch == 'i')
            {
                rev = !rev;
            }
            else
            {
                if(!rev)
                    dq.push_back(ch);
                else
                    dq.push_front(ch);
            }
        }

        string ans = "";

        if(!rev)
        {
            while(!dq.empty())
            {
                ans += dq.front();
                dq.pop_front();
            }
        }
        else
        {
            while(!dq.empty())
            {
                ans += dq.back();
                dq.pop_back();
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    string s1 = "string";
    string s2 = "poiinter";

    cout << "Output 1: "
         << sol.finalString(s1)
         << endl;

    cout << "Output 2: "
         << sol.finalString(s2)
         << endl;

    return 0;
}