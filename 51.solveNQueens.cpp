class Solution {
public:
    vector<vector<int>> queen_placement;

    bool conflict(int x, int y, int xx, int yy) {
        if (x == xx) return true;
        if (y == yy) return true;
        if (x+y == xx + yy) return true;
        if (x-y == xx-yy) return true;

        return false;
    }

    void dfs(int pos, int n, vector<int> path) {
        if (pos >= n) {
            queen_placement.push_back(path);
        }
        int i = pos;
        for (int j = 0; j< n; j++) {
            bool isConflict = false;
            for (int ii = 0; ii<path.size(); ii++) {
                int jj = path[ii];
                if (conflict(i,j,ii,jj)) { 
                    isConflict = true;
                    break;
                }
            }
            if (isConflict) continue;
            path.push_back(j);
            dfs(pos+1, n, path);
            path.pop_back();
        }
        
    }

    vector<vector<string>> solveNQueens(int n) {
        dfs(0, n, vector<int>());
        vector<vector<string>> ans;

        for (int i = 0; i < queen_placement.size(); i++) {
            // for (auto num: queen_placement[i]) {
            //     cout << num << endl;
            // }
            // cout << endl;

            vector<string> solution;

            for (int row = 0; row < n; row++) {
                string tmp = "";
                for (int col = 0; col < n; col++) {
                    if (col == queen_placement[i][row]) tmp += 'Q';
                    else tmp += '.';
                }
                solution.push_back(tmp);
            }

            ans.push_back(solution);
        }

        return ans;
    }
};