class Solution {
public:
    int ans = 0;
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = 0;
        int ans = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                
                if (grid[i][j] == 1) {
                    int cnt = 0;
                    int dx[4] = {0,0,1,-1};
                    int dy[4] = {1,-1,0,0};    

                    for (int d = 0; d < 4; d++) {
                        int ii = i+dx[d];
                        int jj = j+dy[d];
                        if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                        if (grid[ii][jj]) cnt++;
                    }

                    ans += 4- cnt;
                }
            }            
        }

        return ans;
    }
};