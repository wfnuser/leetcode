class Solution {
public:
    int superEggDrop(int K, int N) {
		vector<vector<int>> dp(N + 1, vector<int>(K + 1));
		int m = 0;
		while (dp[m][K] < N) {
			++m;
			for (int j = 1; j <= K; ++j) {
				dp[m][j] = dp[m - 1][j - 1] + dp[m - 1][j] + 1;
			}
		}
		return m;
    }
};