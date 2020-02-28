class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        if (nums.size() == 0) return ans;
        if (nums.size() == 1) {
            ans.push_back(nums[0]);
            return ans;
        }

        unordered_map<int, vector<int>> factors;
        int which = 0;
        int cnt = 0;

        factors[nums[0]].push_back(nums[0]);
        which = nums[0];
        cnt = 1;

        for (int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (factors[nums[j]].size() > factors[nums[i]].size()) {
                        factors[nums[i]] = factors[nums[j]];
                    }
                }
            }
            factors[nums[i]].push_back(nums[i]);
            if (factors[nums[i]].size() > cnt) {
                which = nums[i];
                cnt = factors[nums[i]].size();
            }
        }

        return factors[which];
    }
};