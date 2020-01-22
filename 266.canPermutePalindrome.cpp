class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;

        for (auto c: s) {
            m[c]++;
        }
        int cnt = 0;

        for (auto& v : m) {
            if (v.second % 2 == 1) cnt++;    
        }

        return cnt <= 1;
    }
};