class Solution {
public:

    vector<string> ans;

    void dfs(int left, string& s, int n) {
        if (s.size() == 2*n) {
            if (left == 0) ans.push_back(s);
            return;
        }
        
        s += '(';
        dfs(left+1, s, n);
        s.pop_back();

        if (left > 0) {
            s += ')';
            dfs(left-1, s, n);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        dfs(0, s, n);
        return ans;
    }
};