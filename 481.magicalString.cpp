class Solution {
public:
    int magicalString(int n) {
        int fast = 2;
        int ans = 1;
        if (n == 0) return 0;
        if (n <= 3) return 1;

        string s = "122";
        for (int i = 2; i < n; i++) {
            if (s[i] == '2') {
                if (s[fast] == '2') {
                 s += "11";
                } else {
                 s += "22";
                }
                fast += 2;
            } else {
                ans++;
                if (s[fast] == '1') {
                 s += "2";
                } else {
                 s += "1";
                }
                fast += 1;
            }
        }

        return ans;
    }
};