class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        int cnt = 0;

        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                if (grid[i][j] == '1') {
                    cnt++;

                    queue<pair<int, int>> q;
                    q.push(pair<int, int>(i, j));
                    
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        grid[x][y] = '0';
                        q.pop();

                        if (x - 1 >= 0 && grid[x-1][y] == '1') {
                            q.push({x-1, y}); grid[x-1][y] = '0';
                        }
                        if (x + 1 < m && grid[x+1][y] == '1') {
                            q.push({x+1, y}); grid[x+1][y] = '0';
                        }
                        if (y - 1 >= 0 && grid[x][y-1] == '1') {
                            q.push({x, y-1}); grid[x][y-1] = '0';
                        }
                        if (y + 1 < n && grid[x][y+1] == '1') {
                            q.push({x, y+1}); grid[x][y+1] = '0';
                        }
                    }
                }
            }
        }

        return cnt;
    }
};