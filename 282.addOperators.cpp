class Solution {
public:
    vector<string> ans;
    int target;

    void dfs(string& num, int step, int last, long res, string &str) {
        if (step == num.size()) {
            if (res == target) ans.push_back(str);
            return;
        }
        int originSize = str.size();
        for (int i = step; i < num.size(); i++) {
            string curS = num.substr(step, i - step + 1);
            long cur = stol(curS);
            if (step == 0) {
                str += curS;
                dfs(num, i+1, cur, cur, str);
                str.resize(originSize);
            } else {
                // +
                str += "+" + curS;
                dfs(num, i+1, cur, res+cur, str);
                str.resize(originSize);
                // -
                str += "-" + curS;
                dfs(num, i+1, -cur, res-cur, str);
                str.resize(originSize);
                // *
                str += "*" + curS;
                dfs(num, i+1, last*cur, res-last+last*cur, str);
                str.resize(originSize);
            }
            if (cur == 0) break;
        }
    }

    vector<string> addOperators(string num, int target) {
        this->target = target;
        string s = "";
        dfs(num, 0, 0, 0, s);
        return ans;
    }
};