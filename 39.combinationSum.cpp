class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(int target, vector<int> path, int ith, vector<int>& candidates) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        while(ith<candidates.size() && target >= candidates[ith]) {
            path.push_back(candidates[ith]);
            dfs(target - candidates[ith], path, ith, candidates);
            path.pop_back();
            ith++;
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(target, path, 0, candidates);

        return ans;
    }
};