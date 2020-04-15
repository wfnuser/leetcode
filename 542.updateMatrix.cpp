class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return matrix;
        int n = matrix[0].size();
        if (n == 0) return matrix;

        queue<pair<int, int>> Q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) Q.push(make_pair(i, j));
            }
        }

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!Q.empty()) {
            int size = Q.size();
            for (int cnt = 0; cnt < size; cnt++) {
                pair<int, int> cur = Q.front();
                Q.pop();
                int i = cur.first;
                int j = cur.second;

                for (int d = 0; d < 4; d++) {
                    int ii = i + dx[d];
                    int jj = j + dy[d];

                    if (ii < 0 || jj < 0 || ii >= m || jj >= n) continue;
                    if (matrix[ii][jj] <= 0) continue;
                    matrix[ii][jj] = matrix[i][j] - 1;
                    Q.push(make_pair(ii, jj));
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = -matrix[i][j];
            }
        }

        return matrix;
    }
};