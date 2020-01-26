class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m==0) return;
        int n = board[0].size();
        if (n==0) return;

        // (0, 0) -> 0
        // (0, 1) -> -1
        // (1, 1) -> 1
        // (1, 0) -> -2
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                int dx[8] = {-1,-1,-1,0,0,1,1,1};
                int dy[8] = {1,0,-1,-1,1,1,0,-1};

                for (int d = 0; d < 8; d++) {
                    int ii = dx[d] + i;
                    int jj = dy[d] + j;

                    if (ii<0||ii>=m||jj<0||jj>=n) {
                    } else {
                        if (board[ii][jj] == 1 || board[ii][jj] == -2) {
                            cnt++;
                        }
                    }
                }

                if (cnt > 3 || cnt < 2) {
                    if (board[i][j] != 0) board[i][j] = -2;
                }
                if (cnt == 3) {
                    if (board[i][j] != 1) board[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -2) board[i][j] = 0;
                if (board[i][j] == -1) board[i][j] = 1;
            }
        }
    }
};