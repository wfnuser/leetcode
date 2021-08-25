class Solution {
public:
    int n;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<vector<int>> ans = dfs(graph, 0);

        for (auto &path: ans) {
            reverse(path.begin(), path.end());
        }

        return ans;
    }

    vector<vector<int>> dfs(vector<vector<int>>& graph, int cur) {
        if (cur == n-1) return vector<vector<int>>(1, vector<int>(1, cur));
        vector<vector<int>> ans;
        
        for (auto next: graph[cur]) {
            vector<vector<int>> paths = dfs(graph, next);
            for (auto path: paths) {
                vector<int> copy(path);
                copy.push_back(cur);
                ans.push_back(copy);
            }
        }
        return ans;
    }
};
