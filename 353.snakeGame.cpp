class SnakeGame {
public:

    pair<int, int> head{0,0};
    pair<int, int> tail{0,0};
    queue<string> directions;
    int H;
    int W;
    int cnt = 0;
    vector<vector<int>> graph;
    unordered_map<string, int> m;
    queue<vector<int>> F;

    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        graph = vector<vector<int>>(height, vector<int>(width, 0));
        graph[0][0] = 1;
        for (auto f: food) {
            F.push(f);
        }
        if (!F.empty()) {
            F.pop();
            if (food[0][0] >= 0 && food[0][0] < height && food[0][1] >= 0 && food[0][1] < width){
                graph[food[0][0]][food[0][1]] = 2;
            }
        }
        H = height;
        W = width;
        m["U"] = 0;
        m["L"] = 1;
        m["R"] = 2;
        m["D"] = 3;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int, int> next;
        directions.push(direction);
        switch (m[direction]) {
            case 0:
                next.first = head.first - 1;
                next.second = head.second;
                break;
            case 1:
                next.first = head.first;
                next.second = head.second - 1;
                break;
            case 2:
                next.first = head.first;
                next.second = head.second + 1;
                break;
            case 3:
                next.first = head.first +1;
                next.second = head.second;
                break;
        }
        if (next.first < 0 || next.first >= H || next.second < 0 || next.second >= W) {
            return -1;
        }
        string directionTail = directions.front();
        if (graph[next.first][next.second] == 2) {
            if (!F.empty()) {
                vector<int> f = F.front();
                F.pop();
                if (f[0] >= 0 && f[0] < H && f[1] >= 0 && f[1] < W){
                    if (graph[f[0]][f[1]] == 0) {
                        graph[f[0]][f[1]] = 2;
                    }
                }
            }
            graph[next.first][next.second] = 1;
            head = next;
            return ++cnt;
        }
        directions.pop();
        graph[tail.first][tail.second] = 0;
        switch (m[directionTail]) {
            case 0:
                tail.first = tail.first - 1;
                tail.second = tail.second;
                break;
            case 1:
                tail.first = tail.first;
                tail.second = tail.second - 1;
                break;
            case 2:
                tail.first = tail.first;
                tail.second = tail.second + 1;
                break;
            case 3:
                tail.first = tail.first + 1;
                tail.second = tail.second;
                break;
        }
        if (graph[next.first][next.second] == 1) {
            return -1;
        }
        graph[next.first][next.second] = 1;
        head = next;
        return cnt;        
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */