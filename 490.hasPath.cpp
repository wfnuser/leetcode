class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> Q;
        
        Q.push(make_pair(start[0], start[1]));

        while(!Q.empty()) {
            pair<int, int> pos = Q.front();
            Q.pop();
            if (visited[pos.first][pos.second]) continue;
            if (pos.first == destination[0] && pos.second == destination[1]) return true;
            visited[pos.first][pos.second] = 1;
            int dx[4] = {0,0,1,-1};
            int dy[4] = {1,-1,0,0};

            for (int d = 0; d < 4; d++) {
                int i = pos.first;
                int j = pos.second;
                while((i+dx[d] < m) && (i+dx[d] >= 0) && 
                    (j+dy[d] < n) && (j+dy[d] >= 0) && 
                    maze[i+dx[d]][j+dy[d]] == 0 
                ) {
                    i += dx[d];
                    j += dy[d];
                }
                Q.push(make_pair(i, j));
            }

        }

        return false;
    }
};