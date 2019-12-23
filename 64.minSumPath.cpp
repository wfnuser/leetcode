class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0) return 0;
        vector<vector<int>> sum(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j] = grid[i][j];
                int pre = 0;
                if (i >= 1) pre = sum[i-1][j];
                if (j >= 1 && pre > sum[i][j-1]) pre = sum[i][j-1];
                if (j >= 1 && pre == 0) pre = sum[i][j-1];

                sum[i][j] = sum[i][j] + pre;
            }
        }

        return sum[m-1][n-1];
    }
};