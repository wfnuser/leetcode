class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        if (n <= 1) return 0;

        int min = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (prices[i] < min) {
                min = prices[i];
            } else {
                ans = max(ans, prices[i]-min);
            }
        }

        return ans;
    }
};