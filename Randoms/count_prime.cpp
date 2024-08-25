//https://leetcode.com/problems/count-primes/description/

//bruteforce

class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        for (int i = 2; i < n; i++) {
            int c = 0;
            for (int j = 1; j <= i; j++) {
                if (i % j == 0)
                    c++;
            }
            if (c == 2)
                res++;
        }
        return res;
    }
};