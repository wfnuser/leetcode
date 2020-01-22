class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        unordered_map<char, int> m;

        for (int i = 0; i < size; i++) {
            m[s[i]]++;
        }

        for (int i = 0; i < size; i++) {
            if (m[s[i]] == 1) return i;
        }

        return -1;

    }
};