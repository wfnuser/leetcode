class Solution {
public:
    int max(int a, int b) {
        if (a>b) return a;
        else return b;
    }

    int min(int a, int b) {
        if (a>b) return b;
        else return a;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        int ans = 0;
        vector<int> left(n, 0);
        vector<int> right(n, n-1);
        vector<int> height(n, 0);

        for (int i = 0; i< m; i++) {
            int curL = 0;
            int curR = n-1;
            for (int j = 0; j<n; j++) {
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;  
            }

            for (int j = 0; j<n; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], curL);
                } else {
                    curL = j+1;
                    left[j] = -1;
                }  
            }

            for (int j = n-1; j>=0; j--) {
                if (matrix[i][j] == '1') right[j] = min(right[j], curR);
                else {
                    curR = j-1;
                    right[j] = n;
                }  
            }
            
            for (int j = 0; j<n; j++) {
                ans = max(ans, height[j]*(right[j]-left[j]+1));
            }
        }

        return ans;
    }
};