class Solution {
public:
    unordered_map<char, int> cnt;
    vector<string> ans;
    char odd = ' ';
    int total = 0;

    void dfs(int selected, string& s) {
        if (selected == total) {
            string n = s;
            string rev = n;
            reverse(rev.begin(), rev.end());
            if (odd != ' ') n += odd;
            n += rev;
            ans.push_back(n);
            return;
        }

        for (auto p: cnt) {
            if (p.second == 0) continue;
            cnt[p.first]--;
            s += p.first;
            dfs(selected+1, s);
            s.pop_back();
            cnt[p.first]++;
        }

        return;
    }

    vector<string> generatePalindromes(string s) {
        for (auto c: s) {
            cnt[c]++;
        }
        
        for (auto pair: cnt) {
            if (pair.second % 2 == 1) {
                if (odd != ' ') return ans;
                odd = pair.first;
            }
            cnt[pair.first] /= 2;
            total += cnt[pair.first];
        }
        
        string ss = "";
        dfs(0, ss);
        
        return ans;
    }
};