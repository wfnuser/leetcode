class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = s.size()-1;
        int ans = 0;
        if (j < 0) return ans;
        for (int i = g.size() - 1; i >= 0; i--) {
            if (g[i] <= s[j]) {
                j--;
                ans ++;
            }
            if (j < 0) break;
        }

        return ans;
    }
};