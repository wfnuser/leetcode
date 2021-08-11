class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        // dp[3][2] = 5 -> nums[3]结尾 公差为2 的 等差数列（长度大于2）的个数为 5
        vector<unordered_map<long long, int>> dp(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = (long long) nums[i] - nums[j];
                dp[i][d] += dp[j][d] + 1;
                // dp[j][d] 联合上 dp[i] 表示了长度至少为3的等差数列
                res += dp[j][d];
            }
        }

        return res;
    }
};
