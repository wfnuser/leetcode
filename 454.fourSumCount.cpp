class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> cnt;
        int ans = 0;

        int N = A.size();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int target = -(A[i] + B[j]);
                cnt[target]++;
            }
        }

        for (int k = 0; k < N; k++) {
            for (int l = 0; l < N; l++) {
                int sum = C[k] + D[l];
                ans += cnt[sum];
            }
        }

        return ans;
    }
};