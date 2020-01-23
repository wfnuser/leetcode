class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int l = 1;
        int r = n;

        while(l<r) {
            int mid = l + (r-l)/2;
            long total = (long)mid*(mid+1)/2;
            if (total == n) {
                return mid;
            } else if (total > n) {
                r = mid;
            } else {
                l = mid + 1;
            }

        }

        return l-1;
    }
};