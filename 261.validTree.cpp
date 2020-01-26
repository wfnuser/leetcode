class Solution {
public:
    vector<int> visited;
    vector<vector<int>> graph;

    void dfs(int node){
        for (auto neighbor: graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                dfs(neighbor);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;

        graph = vector<vector<int>>(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][1]].push_back(edges[i][0]);
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        visited = vector<int>(n,0);
        visited[0] = 1;
        dfs(0);

        int sum = 0;
        for (int i = 0; i < visited.size(); i++) {
            sum += visited[i];
        }

        return sum == n;
    }
};