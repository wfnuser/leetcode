class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        string a = text1;
        string b = text2;
        int lena = a.size();
        int lenb = b.size();

        vector<vector<int>> dp(lena, vector<int>(lenb, 0));
        int ans = 0;
        for (int i = 0; i < lena; i++) {
            for (int j = 0; j < lenb; j++) {
                if (i == 0 || j == 0) {
                    if (a[i] == b[j]) dp[i][j] = 1;
                    if (i >= 1) dp[i][j] = max(dp[i-1][j], dp[i][j]);
                    if (j >= 1) dp[i][j] = max(dp[i][j-1], dp[i][j]);
                    
                    ans = max(ans, dp[i][j]);
                    continue;
                }
            
                if (a[i] == b[j]) {
                    dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
                }
                dp[i][j] = max(dp[i][j-1], dp[i][j]);
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                ans = max(ans, dp[i][j]);
            }
        } 
    
        return ans;
    }
};