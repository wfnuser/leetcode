class Solution {
public:
    string s[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        for (auto digit: digits) {
            vector<string> tmp;
            int num = digit - '2';
            for (auto ch: s[num]) {
                if (ans.size() == 0) {
                    string s;
                    s += ch;
                    tmp.push_back(s);
                } else {
                    for (auto s: ans) {
                        tmp.push_back(s+ch);
                    }
                }
            }
            ans = tmp;
        }

        return ans;
    }
};