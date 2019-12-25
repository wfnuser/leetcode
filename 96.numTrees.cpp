class Solution {
public:
    int numTrees(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> num(n+1,0);
        num[0] = 1;
        num[1] = 1;
        num[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j=1; j<=i; j++) {
                num[i] += num[j-1]*num[i-j];
            }
        }
        return num[n];
    }
};