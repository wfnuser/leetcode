class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int state = 0;
        // (node, state)
        queue<pair<int, int>> Q;
        int n = graph.size();
        vector<vector<bool>> vis(n, vector<bool>(1 << n, false));

        for (int i = 0; i < n; i++) {
            Q.push(make_pair(i, state | (1 << i)));
        }

        int step = 0;
        while(!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> t = Q.front();
                Q.pop();
                int node = t.first;
                int state = t.second;
                if (vis[node][state]) continue;
                vis[node][state] = true;
                if (state == (1 << n) - 1) return step;

                for (auto next: graph[node]) {
                    Q.push(make_pair(next, state | (1 << next)));
                }
            }
            step++;
        }

        return 0;
    }
};
