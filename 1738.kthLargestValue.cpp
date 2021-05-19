class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> nums;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> prefix(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = matrix[i][j];
                if (i >= 1) {
                    tmp = tmp ^ prefix[i-1][j];
                }
                if (j >= 1) {
                    tmp = tmp ^ prefix[i][j-1];
                }
                if (i >= 1 && j >= 1) {
                    tmp = tmp ^ prefix[i-1][j-1];
                }
                prefix[i][j] = tmp;
                nums.push_back(tmp);
            }
        }

        sort(nums.begin(), nums.end(), greater<int>());

        return nums[k-1];
    }
};