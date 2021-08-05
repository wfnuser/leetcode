class Solution {
public:
    int m;
    int n;

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0 && !dfs(grid, i, j)) ans++;
            }
        }

        return ans;
    }

    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) return true;
        if (grid[i][j] == 1) return false;
        grid[i][j] = 1;

        bool b1 = dfs(grid, i - 1, j);
        bool b2 = dfs(grid, i + 1, j);
        bool b3 = dfs(grid, i, j - 1);
        bool b4 = dfs(grid, i, j + 1);

        return b1 || b2 || b3 || b4;
    }

};
