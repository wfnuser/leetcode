class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long>> dp(t.size() + 1, vector<long>(s.size() + 1, 0));

        for (long i = 0; i <= s.size(); i++) {
            dp[0][i] = 1;
        }

        for (long i = 1; i <= t.size(); i++) {
            for (long j = 1; j <= s.size(); j++) {
                if (t[i-1] == s[j-1]) {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }


        return dp[t.size()][s.size()];
    }
};