class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.size() == 0) return ans;
        if (words.size() == 0) return ans;

        unordered_map<string, int> cnt;
        int n = words.size();
        int m = words[0].size();

        for (auto word : words) {
            cnt[word]++;
        }

        for (int i = 0; i < m; i++) {
            if (i + n*m > s.size()) break;

            unordered_map<string, int> tmp;
            int left = i;
            
            for (int p = 0; p < n; p++) {
                string word = s.substr(left+p*m, m);
                tmp[word]++;
            }

            while (true) {
                if (isSameMap(tmp, cnt)) ans.push_back(left);
                left += m;
                if (left + n*m > s.size()) break;
                string last = s.substr(left-m, m);
                string next = s.substr(left+(n-1)*m, m);
                tmp[last]--;
                tmp[next]++;
            }
        }

        return ans;
    }

    bool isSameMap(unordered_map<string, int> map1, unordered_map<string, int> map2) {
        for (auto p : map1) {
            if (p.second != map2[p.first]) return false; 
        }
        return true;
    }
};
