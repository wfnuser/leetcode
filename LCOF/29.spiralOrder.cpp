class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        if (n == 0) return ans;

        int u = 0;
        int b = m - 1;
        int l = 0;
        int r = n - 1;

        int i = 0;
        int j = 0;
        while(true) {
            for (j = l; j <= r; j++) {
                ans.push_back(matrix[i][j]);
            }
            u++;
            j--;

            if (u > b) break;
            for (i = u; i <= b; i++) {
                ans.push_back(matrix[i][j]);
            }
            r--;
            i--;

            if (l > r) break;
            for (j = r; j >= l; j--) {
                ans.push_back(matrix[i][j]);
            }
            b--;
            j++;

            if (u > b) break;
            for (i = b; i >= u; i--) {
                ans.push_back(matrix[i][j]);
            }
            l++;
            i++;

            if (l > r) break;
        }

        return ans;
    }
};