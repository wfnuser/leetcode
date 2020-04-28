class Solution {
    int ones(int x) {
        int res = 0;
        for(; x != 0; x = (x & (x - 1))) ++res;
        return res;
    }
    int bricks(int x) { // 最多横着放的砖块计数
        int res = 0;
        while(x) {
            int j = x & (-x);
            if((x & (j << 1))) ++res;
            x &= ~j;
            x &= ~(j << 1);
        }
        return res;
    }
public:
    int domino(int n, int m, vector<vector<int>>& broken) {
        // dp[i][status],i 代表到第 i 行,status 代表当前行的覆盖情况
        int M = (1 << m), blocked[n + 1] = {0}, dp[n + 1][M], maxv = 0;
        memset(dp, 0, M*sizeof(int));
        dp[n][M - 1] = 0, blocked[n] = M - 1; // 最后一行全是障碍
        for(auto v : broken) blocked[v[0]] |= (1 << v[1]);
        for(int l = n - 1; l >= 0; --l)
        for(int st = (~blocked[l]) & (M - 1); ; st = (st - 1) & (~blocked[l])) { // 枚举新增的集合
            int maxcount = 0, S = st & (~blocked[l + 1]);
            for(int k = S;; k = (k - 1) & S) { // 枚举 “竖着放” 的集合
                maxcount = max(ones(k) + bricks(st & (~k)) + dp[l + 1][blocked[l + 1] | k], maxcount);
                if(k == 0) break;
            }
            dp[l][(~st) & (M - 1)] = maxcount;
            if(st == 0) break;
        }
        for(int i = 0; i < M; ++i) maxv = max(maxv, dp[0][i]);
        return maxv;
    }
};