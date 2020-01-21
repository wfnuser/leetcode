class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while(n) {
            if (n&1) {
                n = n>>1;
                if (n) return false;
            } else {
                n = n>>1;
            }
        }
        return true;
    }
};