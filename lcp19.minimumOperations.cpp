class Solution {
public:
    int minimumOperations(string leaves) {
        int len = leaves.size();
        int ans;
        vector<vector<int>> dp(len, vector<int>(3, 0));

        dp[0][0] = (leaves[0] == 'y');
        dp[0][1] = dp[0][2] = dp[1][2] = INT_MAX;
        
        for (int i = 1; i < len; i++) {
            char leaf = leaves[i];

            if (leaf == 'y') {
                dp[i][0] = dp[i-1][0] + 1;
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
                if (i>=2) dp[i][2] = min(dp[i-1][1], dp[i-1][2]) + 1;
            } else {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = min(dp[i-1][1], dp[i-1][0]) + 1;
                if (i>=2) dp[i][2] = min(dp[i-1][1], dp[i-1][2]);
            }
        }

        return dp[len-1][2];
    }
};