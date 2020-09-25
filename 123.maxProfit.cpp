class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        int first = prices[0];
        int second = prices[0];
        int profit1 = 0;
        int profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            first = min(first, prices[i]);
            profit1 = max(profit1, prices[i]-first);
            second = min(second, prices[i] - profit1);
            profit = max(profit, prices[i]-second);
        }

        return profit;
    }
};