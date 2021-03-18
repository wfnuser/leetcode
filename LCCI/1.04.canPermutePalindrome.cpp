class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> cnt;
        for (auto c:s) {
            cnt[c]++;
        }

        int odd = 0;
        for (auto p:cnt) {
            if (p.second % 2 == 1) {
                odd++;
            }
        }

        if (s.size() % 2 == 1) {
            return odd <= 1;
        }
        
        return odd == 0;
    }
};