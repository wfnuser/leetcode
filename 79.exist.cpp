/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (39.88%)
 * Likes:    281
 * Dislikes: 0
 * Total Accepted:    31.3K
 * Total Submissions: 78.5K
 * Testcase Example:
 * '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 *
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 *
 * 示例:
 *
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 *
 * 给定 word = "ABCCED", 返回 true.
 * 给定 word = "SEE", 返回 true.
 * 给定 word = "ABCB", 返回 false.
 *
 */

// @lc code=start
class Solution {
   public:
    bool dfs(string word, int i, int j, int pos, vector<vector<char>>& board) {
        if (pos == word.size() - 1) return true;
        int m = board.size();
        int n = board[0].size();

        char tmp = board[i][j];
        board[i][j] = '0';
        if ((i + 1) < m && board[i + 1][j] == word[pos + 1]) {
            if(dfs(word, i + 1, j, pos + 1, board)) return true;
        }
        if ((i - 1) >= 0 && board[i - 1][j] == word[pos + 1]) {
            if (dfs(word, i - 1, j, pos + 1, board)) return true;
        }
        if ((j + 1) < n && board[i][j + 1] == word[pos + 1]) {
            if(dfs(word, i, j + 1, pos + 1, board)) return true;
        }
        if ((j - 1) >= 0 && board[i][j - 1] == word[pos + 1]) {
            if(dfs(word, i, j - 1, pos + 1, board)) return true;
        }
        board[i][j] = tmp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        if (n == 0) return false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(word, i, j, 0, board)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
