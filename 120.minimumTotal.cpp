class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        int sum = 0;
        if (height == 1) return triangle[0][0];

        for (int i = 1; i < height; i++) {
            triangle[i][0] += triangle[i-1][0];
            for (int j = 1; j <= i-1; j++) {
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
            triangle[i][i] += triangle[i-1][i-1];
        }
        sum = triangle[height-1][0];
        for (int i = 0; i <height; i++) {
            sum = min(sum, triangle[height-1][i]);
        }

        return sum;
    }
};