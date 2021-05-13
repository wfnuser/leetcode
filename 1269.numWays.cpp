class Solution {
public:
    const int MODULO = 1000000007;

    int numWays(int steps, int arrLen) {
        int border = min(steps+1, arrLen);

        vector<vector<int>> dp = vector<vector<int>>(steps+1, vector<int>(border, 0));
        
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j < border; j++) {
                dp[i][j] = dp[i-1][j];
                if (j - 1 >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MODULO;
                }
                if (j + 1 < border) {
                    dp[i][j] = (dp[i][j]+dp[i-1][j+1]) % MODULO;
                }
            }
        }

        return dp[steps][0];
    }
};