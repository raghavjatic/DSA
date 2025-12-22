/*
 * Problem: Keyboard Row
 * Description: Given an array of strings words, return the words that can be typed using letters
 * of the alphabet on only one row of an American keyboard.
 * Link: https://leetcode.com/problems/keyboard-row/
 *
 * Author: Raghav Jatic
 * Date: 23rd December 2025
 */

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> row1(26,0);
        vector<int> row2(26,0);
        vector<int> row3(26,0);

        string a="qwertyuiop";
        string b="asdfghjkl";
        string c="zxcvbnm";

        for(int i=0;i<10;i++)
        {
            row1[a[i] - 'a'] =1;
        }

        for(int i=0;i<9;i++)
        {
            row2[b[i] - 'a'] =1;
        }

        for(int i=0;i<7;i++)
        {
            row3[c[i] - 'a'] =1;
        }

        vector<string> ans;
        string word="";
        for(int i=0;i<words.size();i++)
        {
            string word2=words[i];
            word.resize(word2.size());
            for (int x = 0; x < word2.size(); x++) 
                word[x] = tolower(word2[x]);

            int flag1,flag2,flag3;
            flag1=flag2=flag3=1;
            for(int j=0;j<word.size();j++)
            {
                if(row1[word[j] - 'a']==0)
                    flag1=0;
                if(row2[word[j] - 'a']==0)
                    flag2=0;
                if(row3[word[j] - 'a']==0)
                    flag3=0;
            }

            if(flag1!=0 || flag2!=0 || flag3!=0)
                ans.push_back(word2);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> words1 = {"Hello","Alaska","Dad","Peace"};
    vector<string> res1 = sol.findWords(words1);

    cout << "Result: ";
    for (string &s : res1) cout << s << " ";
    cout << endl;

    vector<string> words2 = {"omk"};
    vector<string> res2 = sol.findWords(words2);

    cout << "Result: ";
    for (string &s : res2) cout << s << " ";
    cout << endl;

    vector<string> words3 = {"adsdf","sfd"};
    vector<string> res3 = sol.findWords(words3);

    cout << "Result: ";
    for (string &s : res3) cout << s << " ";
    cout << endl;

    return 0;
}
