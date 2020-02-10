class Solution {
public:
    
    int waysFrom(int start, vector<int>& nums, long S) {
        if (start == nums.size() - 1) {
            int ans = 0;
            if (nums[start] == S) ans++;
            if (nums[start] == -S) ans++;
            return ans;
        }
        return waysFrom(start+1, nums, S - nums[start]) + waysFrom(start+1, nums, S + nums[start]);
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        return waysFrom(0, nums, (long)S);
    }
};