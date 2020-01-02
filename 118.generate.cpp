class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = vector<vector<int>>(numRows, vector<int>());

        for (int i = 0; i < numRows; i++) {
            ans[i] = vector<int>(i+1,1);
            for (int j = 1; j <= i-1; j++) {
                ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
            }
        }

        return ans;
    }
};