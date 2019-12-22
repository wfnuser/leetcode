class Solution {
public:
    int ans = 0;

    bool conflict(int x, int y, int xx, int yy) {
        if (x == xx) return true;
        if (y == yy) return true;
        if (x+y == xx + yy) return true;
        if (x-y == xx-yy) return true;

        return false;
    }

    void dfs(int pos, int n, vector<int> path) {
        if (pos >= n) {
            ans++;
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

    int totalNQueens(int n) {
        dfs(0, n, vector<int>());
        return ans;
    }
};