class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long> dp(target+1, 0);
        unordered_map<int, int> m;

        for (auto num: nums) {
            m[num]++;
        }

        for (int i = 1; i<=target; i++) {
            if (m[i]) dp[i]++;
            for (int j = 0; j < nums.size(); j++) {
                if (i - nums[j] > 0) {
                    if (dp[i-nums[j]] > INT_MAX - dp[i]) continue;
                    dp[i] += dp[i-nums[j]];
                }
            }
        }

        return dp[target];
    }
};