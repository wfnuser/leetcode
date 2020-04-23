class Solution {
public:
    int coins[4] = {1, 5, 10, 25};

    int waysToChange(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;

        for (int i = 0; i < 4; i++) {
            int coin = coins[i];
            for (int cap = coin; cap <= n; cap++) {
                dp[cap] += dp[cap-coin];
                dp[cap] %= 1000000007;
            }
        }

        return dp[n];
    }
};