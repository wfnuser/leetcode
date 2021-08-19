class Solution {
public:
    int dx[8] = {1,1,1,0,0,-1,-1,-1};
    int dy[8] = {0,1,-1,1,-1,0,1,-1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> Q;
        int m = grid.size();
        int n = grid[0].size();
        int flag = false;
        int ans = 0;

        if (grid[0][0]) return -1;

        Q.push(make_pair(0, 0));

        while(!flag && !Q.empty()) {
            int size = Q.size();

            while(size > 0) {
                size--;
                auto [x, y] = Q.front();
                Q.pop();
                if (x < 0 || y < 0 || x >= m || y >= n) continue;
                if (grid[x][y] == 1) continue;
                if (x == m-1 && y == n-1) {
                    flag = true;
                    break;
                }
                grid[x][y] = 1;

                for (int i = 0; i < 8; i++) {
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    if (xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
                    if (grid[xx][yy] == 1) continue;
                    Q.push(make_pair(xx, yy));
                }

            }

            cout << endl;
            ans++;
        }

        return flag ? ans : -1;
    }
};
