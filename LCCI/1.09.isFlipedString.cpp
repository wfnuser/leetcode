class Solution {
public:
    bool check(string& s1, string& s2, int start) {
        for (int i = start; i < start + s1.size(); i++) {
            if (s1[i%s1.size()] != s2[i-start]) return false;
        }
        return true;
    }

    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == "") return true;

        for (int i = 0; i < s1.size(); i++) {
            if (check(s1, s2, i)) return true;
        }

        return false;
    }
};