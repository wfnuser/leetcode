class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        if (n == 0) return ans;

        for (int i = 0; i <= (m-1)+(n-1); i++) {
            if (i % 2 == 1) {
                for (int x = max(i + 1 - n, 0); x <= min(m-1, i); x++) {
                    ans.push_back(matrix[x][i-x]);
                }
            } else {
                for (int x = max(i + 1 - m, 0); x <= min(n-1, i); x++) {
                    ans.push_back(matrix[i-x][x]);
                }
            }
        }

        return ans;
    }
};