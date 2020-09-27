class Solution {
public:
    int M = 0;
    vector<vector<vector<long>>> dp;
    int numOfArrays(int n, int m, int k) {
        // dp 
        // n; m; k;
        // dp[n][m][k] = dp[]
        
        dp = vector<vector<vector<long>>>(n, vector<vector<long>>(k+1, vector<long>(m+1, 0)));

        for (int i = 0; i < n; i++) {
            for (int cost = 1; cost <= k; cost++) {
                for (int peek = 1; peek <= m; peek++) {
                    if (i == 0) {
                        if (cost == 1) {
                            dp[i][cost][peek] = 1;
                        } else {
                            dp[i][cost][peek] = 0;
                        }
                        continue;
                    }
                    // i cost peek
                    for (int beforePeek = 1; beforePeek < peek; beforePeek++) {
                        dp[i][cost][peek] += dp[i-1][cost-1][beforePeek];
                        dp[i][cost][peek] %= 1000000007;
                    }
                    dp[i][cost][peek] += dp[i-1][cost][peek] * peek;
                    dp[i][cost][peek] %= 1000000007;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            ans += dp[n-1][k][i];
            ans %= 1000000007;
        }

        return ans;
    }
};