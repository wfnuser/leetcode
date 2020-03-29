class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> lands;
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    lands.push(make_pair(i, j));
                }
            }
        }

        if (lands.size() == 0 || lands.size() == m*n) return -1;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!lands.empty()) {
            int size = lands.size();
            for (int c = 0; c < size; c++) {
                pair<int, int> land = lands.front();
                lands.pop();
                int i = land.first;
                int j = land.second;

                if (grid[i][j] == 2) continue;

                for (int d = 0; d < 4; d++) {
                    int ii = i + dx[d];
                    int jj = j + dy[d];
                    if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                    if (grid[ii][jj] == 2 || grid[ii][jj] < 0) continue;

                    cout << ii << " " << jj << endl;

                    if (grid[ii][jj] == 1) {
                        grid[i][j] = 2;
                        lands.push(make_pair(ii, jj));
                        continue;
                    }

                    if (grid[ii][jj] == 0) {
                        if (grid[i][j] >= 1) {
                            grid[ii][jj] = -1;
                        } else {
                            grid[ii][jj] = grid[i][j] - 1;
                        }
                        lands.push(make_pair(ii, jj));
                    }

                    ans = max(ans, -grid[ii][jj]);
                }

                grid[i][j] = 2;
            }
        }
        
        return ans;
    }
};