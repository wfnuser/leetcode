class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool isValid(int d, int cur, int next) {
        if (d == 0) {
            if ((cur == 2 || cur == 3 || cur == 4) && (next == 5 || next == 6 || next == 2)) return true;
        }
        if (d == 1) {
            if ((cur == 2 || cur == 5 || cur == 6) && (next == 3 || next == 4 || next == 2)) return true;
        }
        if (d == 2) {
            if ((cur == 1 || cur == 4 || cur == 6) && (next == 1 || next == 3 || next == 5)) return true;
        }
        if (d == 3) {
            if ((cur == 1 || cur == 3 || cur == 5) && (next == 1 || next == 4 || next == 6)) return true;
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {

        int m = grid.size();
        if (m == 0) return true;
        int n = grid[0].size();
        if (n == 0) return true;

        queue<pair<int, int>> Q;
        Q.push(make_pair(0, 0));

        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            int i = cur.first;
            int j = cur.second;
            cout << i << " " << j << endl;
            if (grid[i][j] < 0) continue;
            grid[i][j] = -grid[i][j];

            if (cur.first == m - 1 && cur.second == n - 1) return true;

            for (int d = 0; d < 4; d++) {
                int ii = i + dx[d];
                int jj = j + dy[d];
                

                if (ii < 0 || jj < 0 || ii >= m || jj >= n) continue;
                if (grid[ii][jj] < 0) continue;
                if (!isValid(d, -grid[i][j], grid[ii][jj])) continue;

                Q.push(make_pair(ii, jj));
            }
        }

        return false;
    }
};