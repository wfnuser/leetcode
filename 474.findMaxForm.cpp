class Solution {
public:
    vector<int> zeros;
    vector<int> ones;

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (auto s: strs) {
            int zero = 0;
            int one = 0;
            for (auto c: s) {
                if (c == '0') zero++;
                if (c == '1') one++;
            }
            zeros.push_back(zero);
            ones.push_back(one);
        }

        for (int i = 0; i < strs.size(); i++) {
            for (int mm = m; mm >= zeros[i]; mm--) {
                for (int nn = n; nn >= ones[i]; nn--) {
                    dp[mm][nn] = max(dp[mm-zeros[i]][nn-ones[i]]+1, dp[mm][nn]);
                }
            }
        }

        return dp[m][n];   
    }
};