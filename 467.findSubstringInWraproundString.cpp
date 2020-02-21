class Solution {
public:
    int findSubstringInWraproundString(string p) {
        unordered_map<char, int> charCnt;
        int ans = 0;
        if (p.size() == 1) return 1;
        if (p.size() == 0) return 0;
        int cnt = 1;
        charCnt[p[0]] = 1;
        for (int i = 1; i < p.size(); i++) {
            if ((p[i]-p[i-1]+26)%26 != 1) {
                cnt = 1;
            } else {
                cnt++;
            }
            charCnt[p[i]] = max(cnt, charCnt[p[i]]);
        }

        for (auto p: charCnt) {
            ans += p.second;
        }

        return ans;
    }
};