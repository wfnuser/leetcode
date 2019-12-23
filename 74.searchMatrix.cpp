class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        int l = 0;
        int r = (m*n) - 1;
        int row = 0;
        int col = 0;
        while(l<r) {
            int mid = (l+r)/2;

            row = mid / n;
            col = mid % n;

            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        } 

        if (matrix[row][col] == target) return true;
        row = r / n;
        col = r % n;
        if (matrix[row][col] == target) return true;


        return false;
    }
};