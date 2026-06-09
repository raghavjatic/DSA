/*
 * Problem: String Compression
 * Description: Compresses a character array in-place by replacing consecutive
 *              repeating characters with the character followed by its count.
 *              If a character appears only once, only the character is kept.
 * Link: https://leetcode.com/problems/string-compression/
 * Author: Raghav Jatic
 * Date: 9th June 2026
 */


//Space Compexity o(1) approach:
// class Solution {
// public:
//     int compress(vector<char>& chars) {
//         string s = "";
//         int p;
//         p = 0;
//         int n = chars.size();
//         int j = 0;
//         int ans = 0;
//         while (p < n) {
//             int q = p;
//             char currchar = chars[p];
//             int currlen = 0;
//             while (q < n && chars[p] == chars[q]) {
//                 currlen += 1;
//                 q += 1;
//             }
//             chars[j] = currchar;
//             j += 1;
//             if (currlen > 1) {

//                 string cnt = to_string(currlen);

//                 for (char c : cnt) {
//                     chars[j++] = c;
//                 }
//             }

//             p = q;
//         }

//         return j;
//     }
// };

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        int p;
        p=0;
        int n = chars.size();
        while (p < n)
        {
            int q = p;
            char currchar = chars[p];
            int currlen=0;
            while(q<n && chars[p] == chars[q])
            {
                currlen += 1;
                q += 1;
            }
            s += currchar;
            if(currlen > 1)
                s += std::to_string(currlen);
            p = q;
        }

        // Copy compressed string back into chars
        for (int j = 0; j < s.size(); j++) {
            chars[j] = s[j];
        }

        return s.size();
    }
};

int main() {
    Solution sol;

    vector<char> chars = {'a','a','b','b','c','c','c'};

    int newLength = sol.compress(chars);

    cout << "Compressed Length: " << newLength << endl;
    cout << "Compressed Array: ";

    for (int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }

    cout << endl;

    return 0;
}