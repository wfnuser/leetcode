class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int pos, vector<int> selected, int k, int n) {
        if (selected.size() == k) {
            ans.push_back(selected);
        }
        if (pos >= n) return;
        for (int i = pos; i<n; i++) {
            selected.push_back(i+1);
            dfs(i+1, selected, k, n);
            selected.pop_back();   
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(0, vector<int>(), k, n);
        return ans;
    }
};