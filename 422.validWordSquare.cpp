class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int m = words.size();
        if (m == 0) return true;
        int n = words[0].size();
        if (m != n) return false;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < words[i].size(); j++) {
                if (j >= m) return false;
                if (i >= words[j].size()) return false;
                if (words[i][j] != words[j][i]) return false;
            }
        }

        return true;
    }
};