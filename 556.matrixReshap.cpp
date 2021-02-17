class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> ans;
        int i = 0;
        
        ans.push_back(vector<int>(0));

        if (nums.size() * nums[0].size() != r * c) return nums;

        for (auto row: nums) {
            for (auto num: row) {
                i++;
                ans.back().push_back(num);
                if (i >= c) {
                    i = 0;
                    ans.push_back(vector<int>(0));
                }
            }
        }

        ans.pop_back();

        return ans;
    }
};