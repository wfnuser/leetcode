class Solution {
public:

    void bfs(vector<vector<char>>& board, int i, int j) {
        queue<pair<int, int>> q;
        q.push(pair<int, int>(i, j));

        vector<pair<int, int>> v;

        int m = board.size();
        int n = board[0].size();
        
        int flag = false;

        while(!q.empty()) {
            int dx[4] = {0,0,1,-1};
            int dy[4] = {1,-1,0,0};
            pair<int, int> p = q.front();
            q.pop();
            v.push_back(p);
            if (p.first == 0 || p.first == m-1 || p.second == 0 || p.second == n-1) {
                flag = true;
            }
            board[i][j] = 'X';

            for (int d = 0; d < 4; d++) {
                int ii = p.first + dx[d];
                int jj = p.second + dy[d];

                if (ii >= 0 && ii < m && jj >= 0 && jj < n && board[ii][jj] == 'O') {
                    board[ii][jj] = 'X';
                    q.push(pair<int, int>(ii, jj));
                }
            }
        }
        if (flag) {
            for (auto p:v) {
                board[p.first][p.second] = 'Y';
            }
        }

    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        if (n == 0) return;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X' || board[i][j] == 'Y') continue;
                if (board[i][j] == 'O') bfs(board, i, j);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'Y' ) board[i][j] = 'O';
            }
        }
    }
};