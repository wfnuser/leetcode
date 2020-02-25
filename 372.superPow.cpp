class Solution {
public:
    int myPow(int a, int b) {
        long res = 1;
        for (int i = 0; i < b; i++) {
            res *= a;
            res %= 1337;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {        
        int res = 1;

        for (auto num: b) {
            res = myPow(res, 10);
            res *= myPow(a, num);
            res %= 1337;
        }

        return res;
    }
};