class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string s = votes[0];
        map<char, map<int, int>> f;

        for (auto vote: votes) {
            for(int i = 0; i < vote.size(); i++) {
                f[vote[i]][i]++;
            }
        }

        sort(s.begin(), s.end(), [&](char a, char b) -> bool {
            for (int i = 0; i < s.size(); i++) {
                if (f[a][i] > f[b][i]) return 1;
                if (f[a][i] < f[b][i]) return 0;
            }
            return a < b;
        });

        return s;
    }
};