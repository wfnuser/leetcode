func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    if obstacleGrid[0][0] == 1 {return 0}
    for i := 0; i < len(obstacleGrid); i++ {
        for j := 0; j < len(obstacleGrid[0]); j++ {
            if i == 0 && j == 0 {
                obstacleGrid[i][j] = 1
                continue
            }
            if (obstacleGrid[i][j] == 1) {
                obstacleGrid[i][j] = 0
            } else {
                obstacleGrid[i][j] = 0;
                if i >= 1 {obstacleGrid[i][j] += obstacleGrid[i-1][j]}
                if j >= 1 {obstacleGrid[i][j] += obstacleGrid[i][j-1]}
            }
        }
    }

    return obstacleGrid[len(obstacleGrid)-1][len(obstacleGrid[0])-1]
}