class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        // find pacific
        queue<pair<int, int>> Q;
        for(int i = 0; i < m; i++) {
            pacific[i][0] = 1;
            Q.push(make_pair(i, 0));
        }
        for(int j = 1; j < n; j++) {
            pacific[0][j] = 1;
            Q.push(make_pair(0, j));
        }
        while(!Q.empty()) {
            pair<int, int> pos = Q.front();
            Q.pop();

            for (int d = 0; d < 4; d++) {
                int ii = pos.first + dx[d];
                int jj = pos.second + dy[d];
                if (ii < 0 || jj < 0 || ii >= m || jj >= n) continue;
                if (pacific[ii][jj]) continue;
                if (matrix[ii][jj] >= matrix[pos.first][pos.second]) {
                    pacific[ii][jj] = 1;
                    Q.push(make_pair(ii, jj));
                }
            }
        }

        for(int i = 0; i < m; i++) {
            atlantic[i][n-1] = 1;
            Q.push(make_pair(i, n-1));
        }
        for(int j = 0; j < n-1; j++) {
            atlantic[m-1][j] = 1;
            Q.push(make_pair(m-1, j));
        }
        while(!Q.empty()) {
            pair<int, int> pos = Q.front();
            Q.pop();

            for (int d = 0; d < 4; d++) {
                int ii = pos.first + dx[d];
                int jj = pos.second + dy[d];
                if (ii < 0 || jj < 0 || ii >= m || jj >= n) continue;
                if (atlantic[ii][jj]) continue;
                if (matrix[ii][jj] >= matrix[pos.first][pos.second]) {
                    atlantic[ii][jj] = 1;
                    Q.push(make_pair(ii, jj));
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});
            }
        }

        return ans;
    }
};