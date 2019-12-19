class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend > INT_MIN) return -dividend;
            else return INT_MAX;
        }

        int sign = 1;
        long a = dividend;
        long b = divisor;
        if (a<0) {
            sign = sign*(-1);
            a = -a;
        }
        if (b<0) {
            sign = sign*(-1);
            b = -b;
        }

        long res = div(a,b);
        if (sign>0) {
            if (res>INT_MAX) return INT_MAX;
            else return res;
        } else {
            return -res;
        }
    }

    long div(long dividend, long divisor) {
        if (dividend < divisor) return 0;
        long tmp = divisor;
        long cnt = 1;
        while (dividend >= tmp + tmp) {
            tmp = tmp + tmp;
            cnt = cnt + cnt;
        }
        return cnt + div(dividend-tmp, divisor);
    }
};