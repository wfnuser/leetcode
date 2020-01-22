class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            return 0;
        }
        if (n == 1) {
            return k;
        }
        int pprev = k;
        int prev = k * k;
        int result = k * k;
        for (int i = 2; i < n; ++i) {
            result = prev * (k - 1) + pprev * (k - 1);
            pprev = prev;
            prev = result;
        }
        return result;
    }
};