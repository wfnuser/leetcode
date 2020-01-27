class Solution {
public:
    static bool cmp(pair<int, char>& a, pair<int, char>& b) {
        return a.first > b.first;
    }

    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        string ans;

        for (auto ch: s) {
            cnt[ch]++;
        }

        vector<pair<int, char>> v;

        for (auto p: cnt) {
            v.push_back(pair<int, char>(p.second, p.first));
        }

        sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].first; j++) {
                ans += v[i].second;
            }
        }

        return ans;
    }
};