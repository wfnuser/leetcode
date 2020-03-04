class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        int oranges = 0;
        queue<pair<int, int>> Q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) oranges++;
                if (grid[i][j] == 2) {
                    Q.push(make_pair(i, j));
                }
            }
        }
        if (oranges == 0) return 0;

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int cnt = -1;
        while(!Q.empty()) {
            cnt++;
            queue<pair<int, int>> nQ;
            while(!Q.empty()){
                pair<int, int> pos = Q.front();
                Q.pop();
                for (int d = 0; d < 4; d++) {
                    int i = pos.first + dx[d];
                    int j = pos.second + dy[d];

                    if (i >= m || i < 0 || j >=n || j < 0) {
                        continue;
                    }
                    if (grid[i][j] == 0) {
                        continue;
                    }

                    if (grid[i][j] == 1) {
                        grid[i][j] = 2;
                        nQ.push(make_pair(i, j));
                    }
                }
            }
            Q = nQ;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return cnt;
    }
};