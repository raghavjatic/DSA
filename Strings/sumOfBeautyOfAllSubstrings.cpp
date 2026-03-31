/**
 * Problem: Sum of Beauty of All Substrings
 * Description: The beauty of a string is the difference between the highest and lowest frequency of characters. Return the sum of beauty of all substrings of s.
 * Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
 * Author: Raghav Jatic
 * Date: 31st March 2026
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int len = s.size();

        for(int i = 0; i < len; i++)
        {
            vector<int> freq(26, 0);

            for(int l = 1; l <= len - i; l++)
            {
                char ch = s[i + l - 1];
                freq[ch - 'a']++;

                int maxi = 0;
                int mini = INT_MAX;

                for(int k = 0; k < 26; k++)
                {
                    if(freq[k] > 0)
                    {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }

                sum += (maxi - mini);
            }
        }

        return sum;
    }
};

int main() {
    Solution obj;

    string s = "aabcb";

    int result = obj.beautySum(s);

    cout << "Sum of Beauty of All Substrings: " << result << endl;

    return 0;
}