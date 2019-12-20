/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check row
        for (int i = 0; i<9; i++) {
            int check[9] = {0};
            for (int j = 0; j<9; j++) {
                if (board[i][j] == '.') continue;
                if (check[board[i][j] - '1'] != 0) {
                    return false;
                }
                check[board[i][j]-'1'] = 1;
            }
        }
        for (int i = 0; i<9; i++) {
            int check[9] = {0};
            for (int j = 0; j<9; j++) {
                if (board[j][i] == '.') continue;
                if (check[board[j][i] - '1'] != 0) return false;
                check[board[j][i]-'1'] = 1;
            }
        }
        for (int i = 0; i<3; i++) {
            for (int j = 0; j<3; j++) {
                int check[9] = {0};
                for (int ii = i*3; ii<i*3+3; ii++) {
                    for (int jj=j*3; jj<j*3+3; jj++) {
                        if (board[ii][jj] == '.') continue;
                        if (check[board[ii][jj] - '1'] != 0) return false;
                        check[board[ii][jj]-'1'] = 1;
                    }
                }
            }
        }
        cout << "pass" << endl;

        return true;
    }
};
// @lc code=end

