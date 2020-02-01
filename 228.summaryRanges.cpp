class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) {
            return ans;
        }   
        if (nums.size() == 1) {
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        int pre = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1] + 1) {
                continue;
            } else {
                if (pre == nums[i-1]) {
                    ans.push_back(to_string(nums[i-1]));
                } else {
                    ans.push_back(to_string(pre)+"->"+to_string(nums[i-1]));
                }
                pre = nums[i];
            }
        }

        if (nums[nums.size()-1] == 1 + nums[nums.size()-2]) {
            ans.push_back(to_string(pre)+"->"+to_string(nums[nums.size()-1]));
        } else {
            ans.push_back(to_string(nums[nums.size() -1]));
        }

        return ans;
    }
};