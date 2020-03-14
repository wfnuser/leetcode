class Solution {
public:
    int lastRemaining(int n, int m) {
        
        vector<int> f(n+1, 0);

        f[1] = 0;
        for (int i = 2; i <= n; i++) {
            f[i] = (f[i-1] + m) % i;
        }

        return f[n];
    }
};