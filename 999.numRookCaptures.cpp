class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return 0;
        int n = board[0].size();
        if (n == 0) return 0;
        
        int x = -1;
        int y = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        if (x == -1) return 0;

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        int ans = 0;
        for (int d = 0; d < 4; d++) {
            int i = x;
            int j = y;

            while(i < m && j < n && i >= 0 && j >= 0) {
                if (board[i][j] == 'B') {
                    break;
                }
                if (board[i][j] == 'p') {
                    ans++;
                    break;
                }
                i += dx[d];
                j += dy[d];
            }
        }

        return ans;
    }
};