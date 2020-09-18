class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int, int> cnt;

    void dfs(int step, int n, vector<int>& path) {
        if (step == n) {
            vector<int> pathcp(path); 
            ans.push_back(pathcp);
            return;
        }

        for (auto p: cnt) {
            if (p.second == 0) continue;
            path.push_back(p.first);
            cnt[p.first]--;
            dfs(step+1, n, path);
            path.pop_back();
            cnt[p.first]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        for (auto num: nums) {
            cnt[num]++;
        }

        vector<int> path;
        dfs(0, n, path);

        return ans;
    }
};