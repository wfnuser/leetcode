class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> m;
        m[k] = -1;
        
        vector<int> partialSum(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            partialSum[i] = sum;
        }
        

        for (int i = 0; i < nums.size(); i++) {
            if (m.find(partialSum[i])!=m.end()) {
                ans = max(i - m[partialSum[i]], ans);
            }
            if (m.find(partialSum[i] + k) == m.end()) {
                m[partialSum[i]+k] = i;
            }
        }

        return ans;
    }
};