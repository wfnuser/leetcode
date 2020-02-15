class TicTacToe {
public:
    int n;
    vector<vector<int>> graph;

    /** Initialize your data structure here. */
    TicTacToe(int n) {
        graph = vector<vector<int>>(n, vector<int>(n, -1));
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        graph[row][col] = player;
        bool win = false;

        for (int i = 0; i < n; i++) {
            if (graph[i][col] != player) {
                break;
            }
            if (i == n-1) return player;
        }
        for (int i = 0; i < n; i++) {
            if (graph[row][i] != player) {
                break;
            }
            if (i == n-1) return player;
        }
        if (row == col) {
            for (int i = 0; i < n; i++) {
                if (graph[i][i] != player) {
                    break;
                }
                if (i == n-1) return player;
            }
        }
        if (row + col == n-1) {
            for (int i = 0; i < n; i++) {
                if (graph[i][n-1-i] != player) {
                    break;
                }
                if (i == n-1) return player;
            }
        }

        return 0;

    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */