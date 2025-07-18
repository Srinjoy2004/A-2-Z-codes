
//https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (divisor == 1)
            return dividend;

        // int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        int sign;
        if ((dividend < 0 && divisor >= 0) || (dividend >= 0 && divisor < 0)) {
            sign = -1;
        } else {
            sign = 1;
        }

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        int ans = 0;

        while (n >= d) {
            int p = 0;
            while (n >= (d << p))
                p++;
            p--;
            n -= (d << p);
            ans += (1 << p);
        }

        return sign * ans;
    }
};