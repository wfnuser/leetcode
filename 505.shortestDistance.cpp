class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rows = maze.size();
        int cols = maze[0].size();
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
        distance[start[0]][start[1]] = 0;
        dfs(maze, start[0], start[1], distance);

        return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
    }

    void dfs(vector<vector<int>>& maze, int pr, int pc, vector<vector<int>>& distance) {
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
            
        for (int i = 0; i < 4; i++) {
            int r = pr + dr[i];
            int c = pc + dc[i];
            int cnt = 0;

            while(true) {
                if (r < 0 || c < 0 || r >= maze.size() || c >= maze[0].size() || maze[r][c] != 0) {
                    break;
                }
                r += dr[i];
                c += dc[i];
                cnt++;
            }

            r -= dr[i];
            c -= dc[i];

            if (distance[pr][pc] + cnt < distance[r][c]) {
                distance[r][c] = distance[pr][pc] + cnt;
                dfs(maze, r, c, distance);
            }
        }

        return;
    }
};