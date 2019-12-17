class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        char pre;
        int pos = 0;
        string prefix = "";
        if (strs.size() == 1) return strs[0];
        for(int i = 0; i < strs.size(); i++) {
            if (pos>=strs[i].size()) break;
            if (i == 0) {
                pre = strs[i][pos];
                continue;
            }

            if (strs[i][pos] != pre) break;
            if (i == strs.size()-1) {
                pos++;
                prefix += pre;
                i = -1;
            }
        }

        return prefix;
    }
};