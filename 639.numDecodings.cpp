class Solution {
public:
    int mod = 1e9+7;
    int numDecodings(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<int> dp(n+1, 0);
        long long cnt = 0;
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int c = 1; c < 10; c++) {
                if (s[i] == '*' || c == (s[i]-'0')) {
                    cnt += dp[i-1];
                }
            }

            for (int c = 10; c <= 26; c++) {
                if (i == 1) break;
                int a = c / 10; // 十位
                int b = c % 10; // 百位
                char pre = s[i-1];
                if (pre == '0') break;
                if (pre == '*' || pre == '0' + a) {
                    if ((s[i] == '*' && b != 0) || s[i] == '0' + b) {
                        cnt += dp[i-2];
                    }
                }
            }
            dp[i] = cnt % mod;
            cnt = 0;
        }

        return dp[n];
    }
};