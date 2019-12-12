class Node {
    public:
        int x;
        int y;
        Node(int xx, int yy) {
            x = xx;
            y = yy;
        }
};

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty()) return;

        int m = rooms.size();
        int n = rooms[0].size();
        int delta[4] = {0, 0, 1, -1}; 
        queue<Node> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) q.push(Node(i,j));
            }
        }

        while(!q.empty()) {
            Node node = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int cur = rooms[node.x][node.y];
                int x = node.x + delta[i];
                int y = node.y + delta[3-i];
                if (x < m && x >= 0 && y < n && y >=0 && rooms[x][y] >= 2147483647) {
                    rooms[x][y] = cur + 1;
                    q.push(Node(x, y));
                } 
            }
        }
    }
};
