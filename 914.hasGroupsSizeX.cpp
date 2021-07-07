class Solution {
public:
    int gcd(int a, int b) {
        if (a < b) return gcd(b, a);
        if (b == 1) return 1;
        if (a % b == 0) return b;
        return gcd(b, a%b);
    }


    bool hasGroupsSizeX(vector<int>& deck) {
        int cnt[10001] = {0};

        for (auto d: deck) {
            cnt[d]++;
        }

        int g = -1;

        for (int i = 0; i <= 10000; i++) {
            if (cnt[i]) {
                if (g == -1) {
                    g = cnt[i];
                } else {
                    g = gcd(g, cnt[i]);
                }
            }
        }

        return g >= 2;
    }
};
