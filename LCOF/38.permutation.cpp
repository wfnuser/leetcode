class Solution {
public:
    vector<string> ans;
    unordered_set<string> S;
    unordered_map<int, int> visited;

    void dfs(string s, string target) {
        if (target.size() == s.size()) {
            if (S.find(target) == S.end()) {
                S.insert(target);
                ans.push_back(target);
            }
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (visited[i]) continue;
            else {
                visited[i] = 1;
                target += s[i];
                dfs(s, target);
                target.pop_back();
                visited[i] = 0;
            }
        }
    }


    vector<string> permutation(string s) {
        dfs(s, "");

        return ans;
    }
};