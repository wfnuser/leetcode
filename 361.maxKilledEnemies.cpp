class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int lastW = -1;
        int sum = 0;
        vector<vector<int>> colCount(m, vector<int>(n, 0));
        vector<vector<int>> rowCount(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            lastW = -1;
            for (int j = 0; j <= n; j++) {
                // i 行 j 列
                if (j == n || grid[i][j] == 'W') {
                    for (int col = lastW+1; col <= j-1; col++) {
                        if (grid[i][col] == 'E') {
                            sum++;
                        }
                    }
                    for (int col = lastW+1; col <= j-1; col++) {
                        rowCount[i][col] = sum;
                    }
                    sum = 0;
                    lastW = j;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            lastW = -1;
            for (int i = 0; i <= m; i++) {
                // i 行 j 列
                if (i == m || grid[i][j] == 'W') {
                    for (int row = lastW+1; row <= i-1; row++) {
                        if (grid[row][j] == 'E') {
                            sum++;
                        }
                    }
                    for (int row = lastW+1; row <= i-1; row++) {
                        colCount[row][j] = sum;
                    }
                    sum = 0;
                    lastW = i;
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    ans = max(ans, colCount[i][j] + rowCount[i][j]);
                }        
            }
        }
        
        return ans;
    }
};