/*
29. Divide Two Integers

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/


class Solution {
public:
    int divide(int dividend, int divisor) {
       
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1 )) return INT_MAX;
        int sign = (dividend < 0) ^ (divisor < 0)? -1: 1;
        
        long long la = labs(dividend), lb = labs(divisor);
        long long res = 0;
        while (la >= lb) {
            long long p = 1;
            long long tmp = lb;
            while (la >= (tmp << 1) ) {
                p = p << 1;
                tmp = tmp << 1;
            }
            la = la - tmp;
            res += p;
        }
        return sign == -1? -res: res;
        
    }
};
