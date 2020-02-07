class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        int i = m-1;
        int j = 0;
        while(i >= 0 && j < n) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) {j++;}
            else {i--;}
        }
        
        return false;
    }
};