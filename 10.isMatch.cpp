class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        if (p[1] == '*') {
            return isMatch(s, p.substr(2)) ||  ((!s.empty()) && ((s[0] == p[0] || p[0] =='.') && isMatch(s.substr(1), p)));
        } else {
            if (s.empty()) return false;
            if (s[0] == p[0] || p[0] == '.') return isMatch(s.substr(1), p.substr(1));
            else return false;
        }

    }
};