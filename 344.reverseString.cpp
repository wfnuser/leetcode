class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size(); i++) {
            int j = s.size() - 1 - i;
            if (i >= j) break;
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
};