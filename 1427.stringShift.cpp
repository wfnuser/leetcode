class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int offset = 0;

        for (auto sh: shift) {
            offset += (sh[0] - 0.5) * 2 * sh[1];
            offset += s.size();
            offset %= s.size();
        }

        string ss = s;

        for (int i = 0; i < s.size(); i++) {
            ss[(i+offset)%s.size()] = s[i];
        }
        return ss;
    }
};