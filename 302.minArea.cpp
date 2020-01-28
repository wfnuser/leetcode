class Solution {
public:
    int left = INT_MAX;
    int right = INT_MIN;
    int top = INT_MAX;
    int bottom = INT_MIN;

    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        if (m == 0) return 0;
        int n = image[0].size();
        if (n == 0) return 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (image[i][j] == '1') {
                    left = min(left, j);
                    top = min(top, i);
                    right = max(right, j);
                    bottom = max(bottom, i);
                }
            }
        }

        return (right - left + 1) * (bottom - top + 1);
    }
};