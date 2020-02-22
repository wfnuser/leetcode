class Solution {
public:
    int countOrders(int n) {
        long dp = 1;
        
        // 计算mod数
        int mod = 1;
        for (int i = 1; i <= 9; i++) {
            mod *= 10;
        }
        mod += 7;
        
        // 这是一道纯数学题
        for (int i = 1; i <= n; i++) {
            // (i-1)时有dp种
            // i-1每个包裹都有两个时刻，分别是pickup和deliver，共计2*(i-1)个时刻
            // pickup[i]有(2*(i-1)+1)个位置可选择
            // 每个位置，deliver只能在pickup之后的间隙里选择，计算总数类似于等差数列求和
            // 当前包裹可插入位置总数*(i-1)包裹的排列总数 即 i个包裹时的排列总数
            dp *= i*(2*i-1);
            dp %= mod;
        }
        
        return dp;
    }
};