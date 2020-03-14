class Solution {
public:
    vector<double> twoSum(int n) {
        int all = 1;
        int sum = n * 6;

        for (int i = 0; i < n; i++) {
            all *= 6;
        }

        vector<double> ans;
        if (n == 1) {
            ans = {0.16667,0.16667,0.16667,0.16667,0.16667,0.16667};
            return ans;
        }

        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

        for (int i = 1; i <= 6; i++) {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int sum = i; sum <= i*6; sum++) {
                for (int j = 1; j <= 6; j++) {
                    if (sum - j >= 1) dp[i][sum] += dp[i-1][sum-j];
                }
            }
        }

        for (int i = n; i <= n*6; i++) {
            ans.push_back((dp[n][i]+0.0) / all);
        }

        return ans;
    }
};