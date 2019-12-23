class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;

        vector<vector<long>> pathCount(m, vector<long>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(obstacleGrid[i][j]) {
                    pathCount[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) pathCount[0][0] = 1;
                else {
                    if (i>0) pathCount[i][j] += pathCount[i-1][j];
                    if (j>0) pathCount[i][j] += pathCount[i][j-1];
                }
            }
        }

        return pathCount[m-1][n-1];     
    }
};