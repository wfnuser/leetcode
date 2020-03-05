class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;

        int m = n / 3;
        int remainder = n % 3;
        if (remainder == 1) {
            return pow(3, m-1)*4;
        }
        
        return pow(3, m)*max(remainder, 1);
    }
};