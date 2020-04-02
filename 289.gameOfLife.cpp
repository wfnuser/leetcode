class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        int dy[] = {-1, -1, -1,  0, 0,  1, 1, 1};
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        if (n == 0) return;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;

                for (int d = 0; d < 8; d++) {
                    int ii = i + dx[d];
                    int jj = j + dy[d];

                    if (ii < 0 || jj < 0 || ii >= m || jj >= n) {
                        continue;
                    }

                    sum += (board[ii][jj]&1);
                }

                if (sum < 2 || sum >=4) {
                    board[i][j] &= 1;
                }
                if (sum == 2) {
                    board[i][j] += (board[i][j]<<1); 
                }
                if (sum == 3) {
                    board[i][j] |= 2;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }

    }
};