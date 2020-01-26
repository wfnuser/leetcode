class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= n; i++) {
            int d = 0;
            for (int tmp = 1; tmp <= sqrt(i); tmp++) {
                dp[i] = min(dp[i-tmp*tmp]+1, dp[i]);
            }
        }   

        return dp[n];
    }
};