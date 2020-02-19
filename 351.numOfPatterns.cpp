class Solution {
public:
    vector<int> dp;
    vector<int> check = vector<int>(9, 0);
    int ans = 0;

    void dfs(int step, int m, int n, int x, int y) {
        if (step >= m && step <= n) {
            ans++;
        }
        if (step == n) {
            return;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (x == i && y == j) continue;
                if (check[i*3+j]) continue;
                if (abs(x-i) % 2 == 0 && abs(y-j) % 2 == 0 && !check[(x+i)/2*3+(y+j)/2]) continue;
                check[i*3+j] = 1;
                dfs(step+1, m, n, i, j);
                check[i*3+j] = 0;
            }
        }
    }

    int numberOfPatterns(int m, int n) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                check[i*3+j] = 1;
                dfs(1, m, n, i, j);
                check[i*3+j] = 0;
            }
        }
        return ans;
    }
};