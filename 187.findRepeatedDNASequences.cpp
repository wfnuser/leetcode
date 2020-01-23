class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        string tmp = "";
        vector<string> ans;
        if (s.size()<10) return ans;

        for (int i = 0; i < 9; i++) {
            tmp = tmp + s[i];
        }

        for (int i = 9; i <= s.size(); i++) {
            tmp = tmp + s[i];
            m[tmp] += 1;
            tmp.erase(tmp.begin());
        }

        for (auto mm: m) {
            if (mm.second > 1) {
                ans.push_back(mm.first);
            }
        }

        return ans;
    }
};