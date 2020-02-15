class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int start = 1; start <=n ;start++) {
                int end = start + i - 1;
                if (end > n) break;
                if (i == 1) dp[start][start] = 0;
                if (i == 2) dp[start][end] = start;
                if (i > 2) {
                    int tmp = start + dp[start+1][end];
                    for (int guess=(start+1); guess < end; guess++) {
                        tmp = min(tmp, max(dp[start][guess-1] + guess, dp[guess+1][end] + guess));
                    }
                    tmp = min(tmp, end + dp[start][end-1]);
                    dp[start][end] = tmp;
                }
            }
        }
        return dp[1][n];
    }
};