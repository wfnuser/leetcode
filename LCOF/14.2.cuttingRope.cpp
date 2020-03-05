class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;

        int m = n / 3;
        int remainder = n % 3;
        if (remainder == 1) {
            return f(3, m-1, 1000000007)*4 % 1000000007;
        }
        
        return f(3, m, 1000000007)*max(remainder, 1) % 1000000007;
    }

    long f(int n, int r, int m) {
        if (r == 1) return n % m;
        if (r % 2 == 0) {
            long tmp = f(n, r/2, m);
            return tmp*tmp%1000000007;
        } else {
            return (f(n, r-1, m) % m) * n % m;
        }
    }

};