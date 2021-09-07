class Solution {
public:
    int balancedStringSplit(string s) {
        int L_R = 0;
        int cnt = 0;

        for (auto c: s) {
            if (c == 'L') L_R++;
            else L_R--;
            if (L_R == 0) cnt++;
        }

        return cnt;
    }
};
