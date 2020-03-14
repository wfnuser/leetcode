class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) return n;

        int i = 9;
        int cnt = 1;
        int tens = 1;

        while(n >= 0) {
            if (n < 9L*tens*cnt) {
                tens *= 10;
                cnt++;
                break;
            }
            n -= 9L*tens*cnt;
            tens *= 10;
            cnt++;
        }
        cnt--;

        int pos = (n - 1) / cnt + 1;
        int mod = (n - 1) % cnt;

        string target = to_string((tens/10) + pos - 1);
        return target[mod] - '0';
    }
};