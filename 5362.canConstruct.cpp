class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        unordered_map<char, int> cnt;
        
        for (auto c: s) {
            cnt[c]++;
        }
        int odd = 0;
        
        for (auto p: cnt) {
            if (p.second % 2 == 1) odd++;
        }
        
        if (odd <= k) return true;
        else return false;
    }
};