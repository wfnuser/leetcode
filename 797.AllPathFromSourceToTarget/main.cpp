class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> pathList;
        vector<int> path;
        int vis[15] = {0};
        
        int n = graph.size();
        int node = 0;
        
        dfs(n, node, graph, path, pathList, vis);
        
        return pathList;
    }
    
    void dfs(int n, int node, vector<vector<int>>& graph, vector<int> path, vector<vector<int>>& pathList, int vis[]) {
        if (vis[node] != 0)
            return;
        vis[node] = 1;
        path.push_back(node);
        if (node == n-1) {
            pathList.push_back(path);
        } else {
            for (int i = 0; i < graph[node].size(); i++) {
                dfs(n, graph[node][i], graph, path, pathList, vis);
            }
        }
        vis[node] = 0;
    }
};
