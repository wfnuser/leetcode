class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;

        for (int l = 0; l < (n+1)/2; l++) {
            for (int step = l; step < n - 1 -l; step++) {
                int tmp = matrix[l][step];
                matrix[l][step] = matrix[n-1-step][l];
                matrix[n-1-step][l] = matrix[n-1-l][n-1-step];
                matrix[n-1-l][n-1-step] = matrix[step][n-1-l];
                matrix[step][n-1-l] = tmp;
            }
        }

        return;
    }
};