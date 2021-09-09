class Solution {
public:
    int MOD = 1000000007;

    int numberOfUniqueGoodSubsequences(string binary) {
        string s = "#" + binary;
        int n = s.size();

        vector<int> last(2, 0);
        vector<int> dp(n, 0);

        int m = 1;

        while (m < n && s[m] == '0') m++;
        if (m == n) return 1;

        dp[m] = 1;

        for (int i = m + 1; i < n; i++) {
            dp[i] = (2 * dp[i-1]) % MOD;
            if (last[s[i] - '0'] - 1 >= 0) dp[i] -= dp[last[s[i] - '0'] - 1];
            dp[i] %= MOD;
            last[s[i] - '0'] = i;
        }

        return (dp[n-1] + (binary.find("0") != -1) + MOD) % MOD;
    }
};
