class Solution {
public:
    double new21Game(int N, int K, int W) {
        int max = K - 1 + W;
        vector<double> dp(max+1, 0);

        if (K == 0) return 1;

        for (int i = max; i >= K; i--) {
            if (i > N) dp[i] = 0;
            else dp[i] = 1;
        }

        for (int j = 1; j <= W; j++) {
            dp[K-1] += dp[j+K-1];
        }
        dp[K-1] = dp[K-1] / W;

        for (int i = K - 2; i >= 0; i--) {
            dp[i] = dp[i+1] + (dp[i+1] - dp[i+W+1]) / W;
        }

        return dp[0];
    }
};