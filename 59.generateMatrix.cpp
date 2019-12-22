class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num = 1;
        int l = 0;
        int t = 0;
        int b = n-1;
        int r = n-1;
        int x = 0;
        int y = 0;
        while(true) {
            for (x=l; x<=r; x++) {
                matrix[y][x] = num;
                num++;
            }
            x--;
            t++;
            if (t>b) break;

            for (y=t; y<=b; y++) {
                matrix[y][x] = num;
                num++;
            }
            y--;
            r--;
            if (l>r) break;

            for (x=r; x>=l; x--) {
                matrix[y][x] = num;
                num++;
            }
            x++;
            b--;
            if (t>b) break;

            for (y=b; y>=t; y--) {
                matrix[y][x] = num;
                num++;
            }
            y++;
            l++;
            if (l>r) break;
        }

        return matrix;
    }
};