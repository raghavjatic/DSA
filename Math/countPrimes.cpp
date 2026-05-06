/*
    Problem Name  : Count Primes
    Description   : Count the number of prime numbers less than n.
    Link          : https://leetcode.com/problems/count-primes/
    Author        : Raghav Jatic
    Date          : 7th May 2026
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {

        if(n <= 2)
            return 0;

        vector<bool> isPrime(n, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i * i < n; i++) {

            if(isPrime[i]) {

                for(int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;

        for(int i = 2; i < n; i++) {

            if(isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};

int main() {

    Solution obj;

    int n = 10;

    cout << "Number of primes less than " << n << " = "
         << obj.countPrimes(n);

    return 0;
}