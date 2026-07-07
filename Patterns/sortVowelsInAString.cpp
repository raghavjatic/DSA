/*
 * Problem: Sort Vowels in a String
 * Description: Sort only the vowels in a string according to their ASCII values
 *              while keeping all consonants in their original positions.
 * Link: https://leetcode.com/problems/sort-vowels-in-a-string/
 * Author: Raghav Jatic
 * Date: 1st July 2026
 * Pattern type: String Manipulation
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' ||
           ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;

        return false;
    }

    string sortVowels(string s) {

        vector<int> upper(5,0);
        vector<int> lower(5,0);

        int n = s.size();

        // Count frequencies
        for(int i=0; i<n; i++)
        {
            if(s[i]=='A') upper[0]++;
            else if(s[i]=='E') upper[1]++;
            else if(s[i]=='I') upper[2]++;
            else if(s[i]=='O') upper[3]++;
            else if(s[i]=='U') upper[4]++;

            else if(s[i]=='a') lower[0]++;
            else if(s[i]=='e') lower[1]++;
            else if(s[i]=='i') lower[2]++;
            else if(s[i]=='o') lower[3]++;
            else if(s[i]=='u') lower[4]++;
        }

        // Fill vowels back in sorted ASCII order
        for(int i=0; i<n; i++)
        {
            if(isVowel(s[i]))
            {
                if(upper[0] > 0)
                {
                    s[i] = 'A';
                    upper[0]--;
                }
                else if(upper[1] > 0)
                {
                    s[i] = 'E';
                    upper[1]--;
                }
                else if(upper[2] > 0)
                {
                    s[i] = 'I';
                    upper[2]--;
                }
                else if(upper[3] > 0)
                {
                    s[i] = 'O';
                    upper[3]--;
                }
                else if(upper[4] > 0)
                {
                    s[i] = 'U';
                    upper[4]--;
                }
                else if(lower[0] > 0)
                {
                    s[i] = 'a';
                    lower[0]--;
                }
                else if(lower[1] > 0)
                {
                    s[i] = 'e';
                    lower[1]--;
                }
                else if(lower[2] > 0)
                {
                    s[i] = 'i';
                    lower[2]--;
                }
                else if(lower[3] > 0)
                {
                    s[i] = 'o';
                    lower[3]--;
                }
                else if(lower[4] > 0)
                {
                    s[i] = 'u';
                    lower[4]--;
                }
            }
        }

        return s;
    }
};

int main()
{
    Solution sol;

    string s1 = "lEetcOde";
    string s2 = "lYmpH";

    cout << "Output 1: "
         << sol.sortVowels(s1)
         << endl;

    cout << "Output 2: "
         << sol.sortVowels(s2)
         << endl;

    return 0;
}