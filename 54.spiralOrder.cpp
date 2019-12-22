class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        int u = 0;
        int l = 0;
        int d = matrix.size()-1;
        int r = matrix[0].size()-1;

        int x = 0;
        int y = 0;
        while(true) {
            for (x=l; x<=r; x++) ans.push_back(matrix[y][x]);
            x--;
            u = u + 1;
            if (u > d) break;
            for (y=u; y<=d; y++) ans.push_back(matrix[y][x]);
            y--;
            r = r - 1;
            if (r < l) break;

            for (x=r; x>=l; x--) ans.push_back(matrix[y][x]);
            x++;
            d = d -1;
            if (u > d) break;
            for (y=d; y>=u; y--) ans.push_back(matrix[y][x]);
            y++;
            l = l + 1;
            if (r < l) break;   
        }

        return ans;

    }
};