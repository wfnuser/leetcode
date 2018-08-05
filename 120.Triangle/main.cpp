class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> l_sum(n, 0);
        vector<int> c_sum(n, 0);
        int ans = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int j = 0;
            c_sum[j] = l_sum[j] + triangle[i][j];
            
            for (j = 1; j < i; j++) {
                c_sum[j] = min(l_sum[j-1], l_sum[j]) + triangle[i][j];

            }
            j = i;
            if (j>0) c_sum[j] = l_sum[j-1] + triangle[i][j];
            
            for (j = 0; j <= i; j++) {
                l_sum[j] = c_sum[j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (ans > c_sum[i]) ans = c_sum[i];
        }
        return ans;
    }
};
