class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "QWERTYUIOPqwertyuiop";
        string row2 = "asdfghjklASDFGHJKL";
        string row3 = "ZXCVBNMzxcvbnm";

        unordered_map<char, int> m;

        for (auto c: row1) {
            m[c] = 1;
        }
        for (auto c: row2) {
            m[c] = 2;
        }
        for (auto c: row3) {
            m[c] = 3;
        }
        vector<string> ans;
        for (auto w: words) {
            if (w.size() == 0) {
                ans.push_back(w);
                continue;
            }
            int pre = m[w[0]];
            bool flag = true;
            for (auto c: w) {
                if (pre != m[c]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans.push_back(w);
        }

        return ans;
    }
};