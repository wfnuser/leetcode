class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < (n+1)/2; i++) {
            int len = n-2*i;
            for (int pad=0; pad<len-1; pad++) {
                int tmp = matrix[i][i+pad];
                matrix[i][i+pad] = matrix[n-1-i-pad][i];
                matrix[n-1-i-pad][i] = matrix[n-1-i][n-1-i-pad];
                matrix[n-1-i][n-1-i-pad] = matrix[i+pad][n-1-i];
                matrix[i+pad][n-1-i] = tmp;
            }
        }   
    }
};