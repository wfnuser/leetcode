class NumMatrix {
public:

    vector<vector<int>> sum; 

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;

        sum = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j] = matrix[i][j];
                if (j-1>=0) sum[i][j] += sum[i][j-1];
                if (i-1>=0) sum[i][j] += sum[i-1][j];
                if (j>=1 && i>=1) sum[i][j] -= sum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (sum.size() == 0 || sum[0].size() == 0) return 0;
        int res = sum[row2][col2];
        if (row1 >= 1) res -= sum[row1-1][col2];
        if (col1 >= 1) res -= sum[row2][col1-1];
        if (row1 >= 1 && col1 >= 1) res += sum[row1-1][col1-1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */