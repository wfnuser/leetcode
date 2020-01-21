class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int size = costs.size();
        vector<vector<int>> dp(size, vector<int>(3, 0));
        if (size == 0) return 0;
        for (int i = 0; i < size; i++) {
            if (i == 0) {
                dp[i][0] = costs[i][0];
                dp[i][1] = costs[i][1];
                dp[i][2] = costs[i][2];
            } else {
                dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
                dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
                dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + costs[i][2];
            }
        }
        int cost = min(dp[size-1][0], dp[size-1][1]);
        cost = min(cost, dp[size-1][2]);
        return cost;
    }
};