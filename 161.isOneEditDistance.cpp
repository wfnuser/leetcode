class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s == t) return false;
        if (abs((int)s.length() - (int)t.length()) >= 2) return false;
        if (s.size() == t.size()) {
            int cnt = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != t[i]) cnt++;
            }
            if (cnt > 1) return false;
            return true; 
        }
        if (s.size() > t.size()) {
            int l = 0;
            while(l < t.size() && s[l] == t[l]) {
                l++;
            }
            while(l < t.size() && s[l+1] == t[l]) {
                l++;
            }
            if (l == t.size()) return true;
            return false;
        }
        int l = 0;
        while(l < s.size() && s[l] == t[l]) {
            l++;
        }
        while(l < s.size() && t[l+1] == s[l]) {
            l++;
        }
        if (l == s.size()) return true;
        return false;
    }
};