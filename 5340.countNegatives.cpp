class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        if (!grid.size()||!grid[0].size()) return cnt;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] < 0) cnt++;
            }
        }
        return cnt;
    }
};