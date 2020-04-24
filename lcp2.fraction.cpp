class Solution {
public:
    vector<int> dfs(vector<int>& cont, int step, int n) {
		if (step == n) {
			return { cont[step], 1 };
		}
		vector<int> ans = dfs(cont, step + 1, n);
		return { cont[step] * ans[0] + ans[1], ans[0] };
    }

    vector<int> fraction(vector<int>& cont) {
        return dfs(cont, 0, cont.size()-1);
    }
};