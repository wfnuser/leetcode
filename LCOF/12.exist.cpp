class Solution {
public:

    vector<int> visited;
    bool found;
    int m, n;

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    void dfs(int step, int i, int j, string& word, vector<vector<char>>& board) {
        if (found) return;
        if (word[step] != board[i][j]) return;
        if (step == word.size()-1) {
            found = true;
            return;
        }
        visited[i*n+j] = 1;
        for (int d = 0; d < 4; d++) {
            int ii = i + dx[d];
            int jj = j + dy[d];
            if (ii < 0 || jj < 0 || ii >= m || jj >= n) continue;
            if (visited[ii*n+jj]) continue;
            dfs(step+1, ii, jj, word, board);
            if (found) return;
        } 
        visited[i*n+j] = 0;
    }

    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        if (m == 0) return false;
        n = board[0].size();
        if (n == 0) return false;
        if (m*n < word.size()) return false;
        if (word.size() == 0) return true;

        stack<pair<int, int>> begins;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    begins.push(make_pair(i, j));
                }
            }
        }
        if (begins.size() == 0) return false;


        while(!begins.empty()) {
            visited = vector<int>(m*n, 0);
            pair<int, int> begin = begins.top();
            begins.pop();
            dfs(0, begin.first, begin.second, word, board);
            if (found) return true;
        }

        return false;
    }
};