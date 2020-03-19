class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        unordered_map<string, unordered_map<string, int>> m;

        for (auto p: pairs) {
            m[p[0]][p[1]] = 1;
            m[p[1]][p[0]] = 1;
        }

        if (words1.size() != words2.size()) return false;

        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] != words2[i] && m[words1[i]][words2[i]] != 1) return false;
        }

        return true;
    }
};