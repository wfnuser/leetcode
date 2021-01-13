class Solution {
public:
    int find(vector<int> &parent, int target) {
        if (parent[target] != target) {
            parent[target] = find(parent, parent[target]);
        }
        return parent[target];
    };

    void Union(vector<int> &parent, int a, int b) {
        parent[find(parent, a)] = find(parent, b);
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(1001, 0);
        vector<int> redundant;

        for (int i = 1; i <= 1000; i++) {
            parent[i] = i;
        }

        for (auto edge: edges) {
            if (find(parent, edge[0]) == find(parent, edge[1])) {
                redundant.push_back(edge[0]);
                redundant.push_back(edge[1]);
                return redundant;
            } else {
                Union(parent, edge[0], edge[1]);
            }
        }

        return redundant;
    }
};