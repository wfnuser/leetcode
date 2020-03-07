class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int sum = 0;
        int ans = nums[0];
        
        for (auto num: nums) {
            sum += num;
            ans = max(sum, ans);
            if (sum <= 0) sum = 0;
        }

        return ans;
    }
};