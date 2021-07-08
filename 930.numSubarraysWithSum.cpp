class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> cnt;
        int sum = 0;
        int ans = 0;

        for (auto num: nums) {
            cnt[sum]++;
            sum += num;
            ans += cnt[sum-goal];
        }

        return ans;
    }
};
