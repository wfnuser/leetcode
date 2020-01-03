class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int slow = 0;
        int fast = 1;
        int profit = 0;

        while(fast < prices.size()) {
            if (prices[slow] < prices[fast]) {
                profit += prices[fast] - prices[slow];
            }
            fast++;
            slow++;
        }

        return profit;
    }
};