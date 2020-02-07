class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;

        vector<int> all;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                all.push_back(matrix[i][j]);        
            }
        }
        sort(all.begin(), all.end());
        
        return all[k-1];
    }
};