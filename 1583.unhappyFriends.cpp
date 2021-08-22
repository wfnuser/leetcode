class Solution {
public:
    unordered_map<int, unordered_map<int, int>> pre;
    
    bool unhappy(int x, int y, int u, int v) {
        if (pre[x][u] > pre[x][y] && pre[u][x] > pre[u][v]) return true;
        if (pre[x][v] > pre[x][y] && pre[v][x] > pre[v][u]) return true;
        return false;
    }

    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                pre[i][preferences[i][j]] = n - 1 - j;
            }
        }

        int ans = 0;

        for (auto p: pairs) {
            int x = p[0];
            int y = p[1];
            
            bool xunhappy = false;
            bool yunhappy = false;

            for (auto p: pairs) {
                int u = p[0];
                int v = p[1];
                if (unhappy(x,y,u,v)) xunhappy = true;
                if (unhappy(y,x,u,v)) yunhappy = true;
                if (xunhappy && yunhappy) break;
            }

            if (xunhappy) ans++;
            if (yunhappy) ans++;
        }

        return ans;
    }
};
