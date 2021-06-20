class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n+1, 0);
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            int num = nums[i-1];
            sum += num;
            preSum[i] = sum;
        }

        unordered_map<int, int> cnt;
        int ans = 0;
        cnt[0] = 1;

        for (int i = 1; i <= n; i++) {
            ans += cnt[preSum[i]-k];
            cnt[preSum[i]]++;
        }

        return ans;
    }
};