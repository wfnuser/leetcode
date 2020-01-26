class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return 0;
        int n = board[0].size();
        if (n == 0) return 0;

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 'X') {
                    continue;
                } else {
                    ans++;
                    int dx[4]={1,-1,0,0};
                    int dy[4]={0,0,1,-1};
                    
                    for (int d = 0; d < 4; d++){
                        int ii = dx[d]+i;
                        int jj = dy[d]+j;

                        if (ii < 0 || ii >= m || jj < 0 || jj >= n) {
                            continue;
                        } else {
                            if (board[ii][jj] == 'X') {
                                int iii = ii;
                                int jjj = jj;
                                while(iii >= 0 && iii < m && jjj >= 0 && jjj < n) {
                                    if (board[iii][jjj] == 'X') {
                                        board[iii][jjj] = 'Y';
                                        iii += dx[d];
                                        jjj += dy[d];
                                    } else {
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'Y') board[i][j] = 'X';
            }
        }

        return ans;
    }
};