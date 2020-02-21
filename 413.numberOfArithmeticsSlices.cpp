class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sum = 0;
        vector<int> dp(A.size(), 0);

        if (A.size() < 3) return 0;

        for (int i = 2; i<A.size(); i++) {
            if (A[i]+A[i-2] == 2*A[i-1]) {
                dp[i] += dp[i-1];
                dp[i]++;
            }
            sum += dp[i];
        }

        return sum;
    }
};