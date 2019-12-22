class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> max(len, 0);
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            max[i] = nums[i];
            if (i>0 && max[i-1]>0) max[i] += max[i-1];
            if (max[i] > ans) ans = max[i];
        }

        return ans;
    
    }
};