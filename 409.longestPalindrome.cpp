class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (auto c:s){
            m[c]++;
        }
        int ans = 0;
        int odd = 0;
        for (auto pair: m) {
            if (pair.second % 2 == 0) {ans += pair.second;}
            else {
                odd++;
                ans += pair.second - 1;
            }
        }
        if (odd) ans += 1;
        return ans;
    }
};