class Solution {
public:
    double myPowCompute(double x, long n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        if (x == 1) return 1;
        if (n < 0) return myPowCompute(1/x, -n);

        if (n % 2 == 0) {
            double tmp = myPowCompute(x, n/2);
            return tmp*tmp;
        } else {
            return x * myPowCompute(x, n-1);
        }
    }

    double myPow(double x, int n) {
        return myPowCompute(x, n);
    }
};