class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, vector<int>& path, int start) {
        if (path.size() >= 2) ans.push_back(path);
        if (start >= nums.size()) return;
        unordered_set<int> s;
        // 如果set里已经记录了当前的值，则跳过；因为之前唤起的dfs里会把之后所有的同样的值都选中；
        // 只需要考虑从之后开始选中的重复的值即可
        for (int i = start; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) continue;
            if (path.size() == 0) {
                s.insert(nums[i]);
                path.push_back(nums[i]);
                dfs(nums, path, i+1);
                path.pop_back();
            } else {
                if (nums[i] >= path.back()) {
                    s.insert(nums[i]);
                    path.push_back(nums[i]);
                    dfs(nums, path, i+1);
                    path.pop_back();
                }
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;
        dfs(nums, path, 0);
        return ans;
    }
};