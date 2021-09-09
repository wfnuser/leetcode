class Solution {
public:
    int MOD = 1000000007;
    int distinctSubseqII(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        vector<int> dp(n+1);
        vector<int> last(26, -1);
        
        dp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            dp[i+1] = dp[i] * 2 % MOD;
            if (last[s[i] - 'a'] >= 0) {
                dp[i+1] -= dp[last[s[i] - 'a']];
            }
            dp[i+1] %= MOD;
            last[s[i] - 'a'] = i;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};
