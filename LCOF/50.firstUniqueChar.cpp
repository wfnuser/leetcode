class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char ,int> cnt;

        for (auto c: s) {
            cnt[c]++;
        }

        for (auto c: s) {
            if (cnt[c] == 1) return c;
        }

        return ' ';
    }
};