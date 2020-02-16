class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 1;

        if (l == r) {
            return 0;
        }
        int terminal = nums[l+(r-l)/2];
        int ans = 0;
        for (auto num: nums) {
            ans += abs(terminal-num);
        }

        return ans;
    }
};