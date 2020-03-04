class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        int l1 = 1;
        int l2 = 1;

        for (int i=3; i <= n; i++) {
            int tmp = (l1 + l2) % 1000000007;
            l1 = l2;
            l2 = tmp;
        }

        return l2;
    }
};