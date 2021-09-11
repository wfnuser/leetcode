class Solution {
public:
    int findIntegers(int n) {
        vector<vector<int>> dp(32, vector<int>(2, 0));
        dp[0][0] = 1;
        dp[0][1] = 1;

        for (int i = 1; i < 32; i++) {
            dp[i][1] = dp[i-1][0];
            dp[i][0] = dp[i-1][0] + dp[i-1][1];
        }

        int len = 0;
        for (len = 32; len > 0; len--) {
            if ((n >> (len-1)) & 1) break;
        }

        int pre = -1;
        int ans = 0;
        
        for (; len > 0; len--) {
            int cur = (n >> (len - 1)) & 1;
            if (cur == 1) ans += dp[len-1][0];
            if (cur == pre && cur == 1) break;

            pre = cur; 
            if (len == 1) ans++;
        }
        
        return ans;
    }
};
