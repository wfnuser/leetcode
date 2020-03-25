class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {

        int updown = 0;

        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        int other = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) updown++;

                for (int d = 0; d < 4; d++) {
                    int ii = i + dx[d];
                    int jj = j + dy[d];

                    if (ii < 0 || jj < 0 || ii >= m || jj >= n) {
                        other += grid[i][j] * 1;
                    } else {
                        if (grid[ii][jj] >= grid[i][j]) {}
                        else other += (grid[i][j] - grid[ii][jj]);
                    }
                }

            }
        }

        return updown*2 + other;
    }
};