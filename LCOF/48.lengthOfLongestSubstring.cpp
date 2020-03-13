class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> cnt;

        int l = 0;
        int r = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {
            cnt[s[r]]++;
            if (cnt[s[r]]>=2) {
                while(true) {
                    cnt[s[l]]--;
                    if (s[l] == s[r]) {
                        l++;
                        break;
                    }
                    l++;
                }
            }
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};