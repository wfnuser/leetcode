class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> org = nums;
        sort(nums.rbegin(), nums.rend());
        unordered_map<int, string> order;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= 3) order[nums[i]] = to_string(i+1);
            if (i == 0) order[nums[i]] = "Gold Medal";
            if (i == 1) order[nums[i]] = "Silver Medal";
            if (i == 2) order[nums[i]] = "Bronze Medal";
        }

        vector<string> res(nums.size(), "");
        for (int i = 0; i < res.size(); i++) {
            res[i] = order[org[i]];
        }

        return res;
    }
};