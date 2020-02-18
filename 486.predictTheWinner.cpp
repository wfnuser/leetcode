class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size(), 0));

        for (int s = nums.size()-1; s>=0; s--) {
            for (int e = s+1; e < nums.size(); e++) {
                int left = nums[s] - dp[s+1][e];
                int right = nums[e] - dp[s][e-1];
                dp[s][e] = max(left, right);
            }
        }
        
        return dp[0][nums.size()-1] >= 0;
    }
};