class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int src = 0;
        int color[110] = {-1};
        for (int i =0; i < 110; i++) {
            color[i] = -1;
        }
        queue<int> q;
        for (int c = 0; c < graph.size(); c++){
            if (color[c]!=-1){
                continue;
            }
            q.push(c);
            color[c] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (graph[u].size() == 0) {
                    u++;
                    if (u < graph.size())
                        q.push(u);
                    continue;
                }
                for (int i = 0; i < graph[u].size(); i++) {
                    int v = graph[u][i];

                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else {
                        if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
