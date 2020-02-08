class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return vector<int>{0};
        vector<int> degree(n, 0);
        unordered_map<int, vector<int>> graph;

        for (auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> Q;
        int rst = n;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) Q.push(i);
        }

        while(rst >= 3) {
            rst -= Q.size();
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                int node = Q.front();
                Q.pop();
                degree[node] = 0;
                for (auto next: graph[node]) {
                    if (!degree[next]) continue;
                    degree[next]--;
                    if (degree[next] == 1) {
                        Q.push(next);
                    }
                }
            }  
        }

        vector<int> ans;
        while(!Q.empty()) {
            ans.push_back(Q.front());
            Q.pop();
        }

        return ans;
    }
};