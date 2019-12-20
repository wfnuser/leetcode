/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int target, vector<int> path, int ith, vector<int>& candidates, bool lastHasBeenSelected) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (ith<candidates.size() && target >= candidates[ith]) {
            if (ith>0 && candidates[ith] == candidates[ith-1]) {
                if (lastHasBeenSelected) {
                    path.push_back(candidates[ith]);
                    dfs(target-candidates[ith], path, ith+1, candidates, true);
                    path.pop_back();
                }
            } else {
                path.push_back(candidates[ith]);
                dfs(target-candidates[ith], path, ith+1, candidates, true);
                path.pop_back();
            }
            dfs(target, path, ith+1, candidates, false);

        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(target, path, 0, candidates, true);

        return ans;
    }
};
// @lc code=end

