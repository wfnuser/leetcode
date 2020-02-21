class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(3));
        // dp[i][0]: 当前可买未买或当前冷冻
        // dp[i][1]: i持股
        // dp[i][2]: i卖出
        if (prices.size() <= 1) return 0;
        
        dp[0][0] = 0; // 刚卖出
        dp[0][1] = -prices[0];
        dp[0][2] = 0;

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
            dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1]);
            dp[i][2] = dp[i-1][1] + prices[i];
        }

        return max(dp[prices.size()-1][0], dp[prices.size()-1][2]);
    }
};