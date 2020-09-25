class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // status includes: day;deals;status
        // deals range in 0 ... k
        // status: 0 -> hold; 1 -> not hold
        // dp[i][j][s]
        // dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j+1][1])
        int n = prices.size();
        if (n <= 1) return 0;
        if (k >= n/2) return maxProfitInf(prices);

        vector<vector<int>> dp = vector<vector<int>>(k+1, vector<int>(2, 0));

        for (int i = 0; i <= k; i++) {
            dp[i][0] = -prices[0];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                // not hold
                dp[j][1] = max(dp[j][1], dp[j][0] + prices[i]);
                // hold
                dp[j][0] = max(dp[j][0], dp[j-1][1] - prices[i]);
            }
        }

        return dp[k][1];
    }

    int maxProfitInf(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        if (n <= 1) return ans;

        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i-1]) ans += prices[i] - prices[i-1];
        }
        
        return ans;
    }
};