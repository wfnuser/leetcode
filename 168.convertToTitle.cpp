class Solution {
public:
    string convertToTitle(int n) {
        char A = 'A';
        string ans = "";
        if (n == 1) return "A";

        while(n) {
            int m = n % 26;
            if (m == 0) {
                m = 26;
                n--;
            }
            ans = (char)((int)A + m - 1) + ans;
            if (n == 26) break;
            n = n / 26;
        }

        return ans;
    }
};