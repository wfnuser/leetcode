class Solution {

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> rgraph;
        vector<int> nodes;
        vector<int> safe(graph.size());
        queue<int> q;
        
        for (int i=0; i<graph.size(); i++) {
            vector<int> neighbors;
            rgraph.push_back(neighbors);
            if (graph[i].size() == 0) {
                q.push(i);
                safe[i] = 1;
            }
        }
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                rgraph[graph[i][j]].push_back(i);
            }
        }
        
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            for (int i = 0; i < rgraph[f].size(); i++) {
                int v = rgraph[f][i];
                int status = true;
                for (int j = 0; j < graph[v].size(); j++) {
                    if (safe[graph[v][j]] != 1)
                        status = false;
                }
                if (status) {
                    q.push(v);
                    safe[v] = 1;
                }
            }
        }
        
        for (int i=0; i < graph.size(); i++) {
            if (safe[i]) nodes.push_back(i);
        }
        return nodes;
    }
};
