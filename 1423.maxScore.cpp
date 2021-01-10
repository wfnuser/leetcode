class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        if (cardPoints.size() <= k) {
            for (auto c: cardPoints) {
                sum += c;
            }
            return sum;
        }

        int ans = 0;
        int left = 0;
        for (left = 0;left < k;left++) {
            sum += cardPoints[left];
        }
        left--;

        ans = sum;
        for (int i = cardPoints.size() - 1; i >= cardPoints.size() - k; i--) {
            sum -= cardPoints[left];
            left--;
            sum += cardPoints[i];
            if (ans < sum) ans = sum;
        }

        return ans;
    }
};