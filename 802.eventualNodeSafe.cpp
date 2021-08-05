class Solution {
public:
    vector<int> color;
    
    bool isSafe(int source, vector<vector<int>>& graph) {
        if (color[source] > 0) return color[source] == 2;
        color[source] = 1;

        for (auto node: graph[source]) {
            if (isSafe(node, graph) == false) return false;
        }

        color[source] = 2;

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        color = vector<int>(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (isSafe(i, graph)) ans.push_back(i);
        }

        return ans;
    }
};
