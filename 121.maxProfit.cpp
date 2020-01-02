class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size <= 1) return 0;
        int ans = 0;
        vector<int> min(size, INT_MAX);
        vector<int> max(size, INT_MIN);

        for (int i = 0; i<size; i++) {
            if (prices[i] < min[i]) min[i] = prices[i];
            if (i>=1 && min[i-1] < min[i]) min[i] = min[i-1];   
        }
        for (int i = size-1; i>=0; i--) {
            if (prices[i] > max[i]) max[i] = prices[i];
            if (i<size-1 && max[i+1] > max[i]) max[i] = max[i+1];   
        }

        for (int i=0; i < size; i++) {
            if (max[i]-min[i] > ans) ans = max[i] - min[i];
        }

        return ans;
    }
};