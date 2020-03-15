class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        if (m == 0) return ans;
        int n = grid[0].size();
        if (n == 0) return ans;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                else {
                    queue<pair<int, int>> Q;
                    Q.push(make_pair(i, j)); 
                    int area = 0;
                    while(!Q.empty()) {
                        pair<int, int> cur = Q.front();
                        Q.pop();
                        grid[cur.first][cur.second] = 0;
                        area++;

                        for (int d = 0; d < 4; d++) {
                            int x = cur.first + dx[d];
                            int y = cur.second + dy[d];
                            if (x >= m || y >= n || x < 0 || y < 0) continue;
                            if (grid[x][y]) { 
                                grid[x][y] = 0;
                                Q.push(make_pair(x, y));
                            }
                        }
                    }

                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};