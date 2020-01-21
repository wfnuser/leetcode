/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (38.72%)
 * Likes:    210
 * Dislikes: 0
 * Total Accepted:    19.2K
 * Total Submissions: 49.5K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * 输出: 4
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == '1') { dp[i][0] = 1; ans = 1;}
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == '1') {dp[0][j] = 1; ans = 1;}
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') { 
                    dp[i][j] = 1;
                    if (dp[i-1][j-1]>=1 && dp[i-1][j] >= dp[i-1][j-1] && dp[i][j-1] >= dp[i-1][j-1]) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return ans*ans;
    }
};
// @lc code=end