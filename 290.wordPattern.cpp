class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> cmap;
        int cindex = 1;
        unordered_map<string, int> smap;
        int sindex = 1;

        string cs = "";
        string ss = "";

        for (auto c: pattern) {
            if (!cmap[c]) {
                cmap[c] = cindex;
                cindex++;
            }
        }
        for (auto c: pattern) {
            char ch = '0' + cmap[c];
            cs += ch;
        }

        vector<string> v;
        string pre = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                if (!smap[pre]) {
                    smap[pre] = sindex;
                    char ch = '0' + sindex;
                    ss += ch;
                    sindex++;
                } else {
                    char ch = '0' + smap[pre];
                    ss += ch;
                }
                pre = "";
            } else {
                pre = pre + str[i];
            }
        }
        if (!smap[pre]) {
            smap[pre] = sindex;
            char ch = '0' + sindex;
            ss += ch;
            sindex++;
        } else {
            char ch = '0' + smap[pre];
            ss += ch;
        }

        return cs == ss;

    }
};