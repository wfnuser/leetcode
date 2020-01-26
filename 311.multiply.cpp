class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        
        int mA = A.size();
        int nA = A[0].size();
        int mB = B.size();
        int nB = B[0].size();

        ans = vector<vector<int>>(mA, vector<int>(nB, 0));

        for (int i = 0; i < mA; i++) {
            for (int j = 0; j < nB; j++) {
                ans[i][j] = 0;
                for (int k = 0; k < nA; k++) {
                    ans[i][j] += A[i][k]*B[k][j];
                }
            }
        }

        return ans;
    }
};