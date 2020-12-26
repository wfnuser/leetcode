class Solution {
public:
    int factorial(int n) {
        if (n <= 1) return 1;
        return n*factorial(n-1);
    }

    int comb(int m, int n) {
        return factorial(n) / factorial(m) / factorial(n - m);
    }

    int paintingPlan(int n, int k) {
        if (n * n == k) return 1;
        
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                int sum = i * n + j * n - i * j;

                if (sum == k) {
                    ans += comb(i, n) * comb(j, n);
                }
            }
        }

        return ans;
    }

};