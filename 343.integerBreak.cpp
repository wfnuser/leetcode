class Solution {
public:
    int integerBreak(int n) {
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (n == 3) return 2;

        vector<int> dp(n+1, 0);
        for (int i = 0; i <= n; i++) {
            dp[i] = i;
        }

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i],dp[i-j]*dp[j]);
            }
        }

        return dp[n];
    }
};