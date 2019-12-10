class Solution {
public:
    vector<vector<int>> path;
    vector<int> quiet;
    vector<int> quietest; // quietest node

    // return the quietest node
    int quietest_richer(int node) {
        if (quietest[node] != -1) return quietest[node];
        int res = node;
        for (int i = 0; i < path[node].size(); i++) {
            int new_richer_quiet = quiet[quietest_richer(path[node][i])];
            if (quiet[res] > new_richer_quiet) {
                res = quietest_richer(path[node][i]);
            }
        }
        quietest[node] = res;
        return res;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> root(n, 1);
        this->quiet = quiet;
        this->quietest.resize(n, -1);
        this->path.resize(n, vector<int>());

        for (int i = 0; i < richer.size(); i++) {
            int x = richer[i][0];
            int y = richer[i][1];
            root[x] = 0;
            path[y].push_back(x);
        }

        for (int i = 0; i < n; i++) {
            if (root[i]) quietest_richer(i);
        }

        return quietest;
    }
};
