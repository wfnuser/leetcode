#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

class Solution {
   public:
    vector<pair<int, int> > path;
    vector<vector<char> > tmp;
    vector<set<char>> row = vector<set<char>>(9);
    vector<set<char>> column = vector<set<char>>(9);
    vector<set<char>> block = vector<set<char>>(9);
    bool found = false;

    bool check(int i, int j) {
        char num = tmp[i][j];
        cout << "checking" << endl;
        cout << num << endl;
        if (row[i].find(num) != row[i].end() ) {
            return false;
        }
        if (column[j].find(num) != column[j].end()) {
            return false;
        }
        if (block[i/3*3+j/3].find(num) != block[i/3*3+j/3].end()) {
            return false;
        }
        cout << "check pass." << endl;
        row[i].insert(num);
        column[j].insert(num);
        block[i/3*3+j/3].insert(num);
        return true;
    }

    void dfs(vector<vector<char>>& board, int i) {
        if (found) return;
        if (i >= path.size()) {
            found = true;
            return;
        }
        for (int j = 0; j < 9; j++) {
            if (found) return;
            char num = '1' + j;
            tmp[path[i].first][path[i].second] = '1' + j;
            if (!check(path[i].first, path[i].second))
                continue;
            else {                
                if ((i+1)>=path.size()) {
                    found = true;
                    return;
                }
                dfs(board, i + 1);
                row[path[i].first].erase(row[path[i].first].find(num));
                column[path[i].second].erase(column[path[i].second].find(num));
                block[path[i].first/3*3+path[i].second/3].erase(block[path[i].first/3*3+path[i].second/3].find(num));
            }
        }
        if (found) return;
        tmp[path[i].first][path[i].second] =
            board[path[i].first][path[i].second];
    }

    void solveSudoku(vector<vector<char> >& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    path.push_back(make_pair(i, j));
                } else {
                    row[i].insert(board[i][j]);
                    column[j].insert(board[i][j]);
                    block[i/3*3+j/3].insert(board[i][j]);
                }
            }
        }
        tmp = board;
        dfs(board, 0);
        board = tmp;
    }
};


Solution sol = Solution();

int main() {
    vector<vector<char> > matrix{ {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    sol.solveSudoku(matrix);
}