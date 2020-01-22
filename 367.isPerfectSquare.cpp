class Solution {
public:
    bool isPerfectSquare(int num) {
        long numL = num;
        if (num == 1) return true;
        for (long i = 2; i*i<=numL; i++) {
            int cnt = 0;
            while(numL%i==0) {
                numL = numL/i;
                cnt++;
            }
            if (cnt % 2 == 1) return false;
        }
        if (numL != 1) return false;
        return true;
    }
};