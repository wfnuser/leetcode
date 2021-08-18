class Solution {
public:
    int checkRecord(int n) {
        int mode = 1e9 + 7;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, 0)));
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        dp[0][1][0] = 1;
        for (int i = 1; i < n; ++i)
        {
            dp[i][0][0] = ((dp[i - 1][0][0] + dp[i - 1][0][1]) % mode + dp[i - 1][0][2]) % mode;
            dp[i][0][1] = dp[i - 1][0][0];
            dp[i][0][2] = dp[i - 1][0][1];
            dp[i][1][0] = (((dp[i][0][0] + dp[i - 1][1][0]) % mode + dp[i - 1][1][1]) % mode + dp[i - 1][1][2]) % mode;
            dp[i][1][1] = dp[i - 1][1][0];
            dp[i][1][2] = dp[i - 1][1][1];
        }
        int ans = 0;
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                ans += dp[n - 1][i][j];
                ans %= mode;
            }
        }
        return ans;
    }
};
