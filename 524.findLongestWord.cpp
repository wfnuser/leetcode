class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        int ps = 0;
        int pw = 0;

        for (auto w: dictionary) {
            ps = 0;
            pw = 0;
            if (w.size() < ans.size()) continue;
            // 双指针 - 序列包含问题
            while (pw < w.size() && ps < s.size()) {
                if (s[ps] == w[pw]) {
                    // 两个指针所指字符相等 同时后移
                    ps++;
                    pw++;
                } else {
                    // 不等 后移源指针
                    ps++;
                }
            }
            // 如果pw没有到达最后的位置 说明不够称包含关系
            if (pw < w.size()) continue;
            if (w.size() > ans.size()) {
                ans = w;
                continue;
            }
            if (w.size() == ans.size() && w < ans) {
                ans = w;
            }
        }

        return ans;
    }
};
