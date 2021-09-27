class Solution {
public:
    const int mod = 1000000007;

    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<long long> dp(n, 0); // first day come to n

        dp[0] = 0;
        dp[1] = 2;

        for (int i = 2; i < n; i++) {
            dp[i] = (dp[i-1] + (dp[i-1] - dp[nextVisit[i-1]]) % mod + mod + 2) % mod;
        }

        return dp[n-1];
    }
};
