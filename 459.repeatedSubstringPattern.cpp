class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1) return false;

        for (int i = 1; i < s.size(); i++) {
            if (s.size() % i != 0) continue;
            bool flag = true;
            for (int j = 0; j < i; j++) {
                char pre = s[j];
                int p = j;
                while(p < s.size()) {
                    if (s[p] != pre) {
                        flag = false;
                        break;
                    }
                    p += i;
                }
                if (!flag) break;
            }
            if (flag) return true;
        }

        return false;
    }
};