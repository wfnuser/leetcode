class Solution {
public:
    void reverseWords(vector<char>& s) {
        int N = s.size();
        int l = 0;
        int r = N - 1;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
        l = 0;
        while (l < N && s[l] == ' ') ++l;
        for (r = l; r < N; ++r) {
            if (s[r] == ' ' && r > l) {
                int tl = l;
                int tr = r - 1;
                while (tl < tr) {
                    swap(s[tl++], s[tr--]);
                }
                l = r;
                while (l < N && s[l] == ' ') ++l;
            }
        }
        r = N - 1;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
};