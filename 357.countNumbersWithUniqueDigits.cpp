class Solution {
   public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;

        int sum = 10;
        int dp = 9;

        for (int i = 2; i <= min(10, n); i++) {
            dp *= 11 - i;
            sum += dp;
        }

        return sum;
    }
};