class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> leader(n, 0);

        for (int i = 0; i < n; i++) {
            leader[i] = i;
        }

        for (auto edge: edges) {
            int small = min(edge[0], edge[1]);
            int large = max(edge[0], edge[1]);
            while(leader[small] != small) {
                small = leader[small];
            }
            while(leader[large] != large) {
                large = leader[large];
            }

            leader[max(small, large)] = min(small, large);
        }

        vector<int> visited(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            else {
                int j = i;
                vector<int> v;
                while(leader[j] != j) {
                    v.push_back(j);
                    j = leader[j];
                }
                for (auto e: v) {
                    leader[e] = j;
                    visited[e] = 1;
                }
                if (!visited[j]) ans++;
                visited[j] = 1;
            }
        }

        return ans;
    }
};