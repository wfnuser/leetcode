class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        vector<int> partialSum(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            partialSum[i] = sum;
        }
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (partialSum[i] == k) ans = i+1;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (k == partialSum[j] - partialSum[i]) {
                    ans = max(j-i, ans);  
                }
            }
        }

        return ans;
    }
};