class Solution {
public:

    void setRowAndCol(vector<vector<int>>& matrix, int m, int n, int i, int j) {
        for (int row = 0; row < m; row++) {
            if (matrix[row][j] != 0) matrix[row][j] = INT_MIN + 123345;
        }
        for (int col = 0; col < n; col++) {
            if (matrix[i][col] != 0) matrix[i][col] = INT_MIN + 123345;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) setRowAndCol(matrix, m, n, i, j);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == INT_MIN + 123345) matrix[i][j] = 0;
            }
        }
    }
};