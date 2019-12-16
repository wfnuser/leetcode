class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        int ans = 0;
        if (x == INT_MIN) return 0;
        if (x<0) {
            x=-x;
            flag = -1;
        }

        while(x>0) {
            if (ans > INT_MAX / 10) return 0;
            ans *= 10;
            ans += x%10;
            x /= 10;
        }
        return flag*ans;
    }
};