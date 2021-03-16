class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int l = 0;
        int r = 0;

        unordered_map<char, int> cnt;
        int kinds = 0;
        int ans = 0;

        while(r<s.size()) {
            if (cnt[s[r]] == 0) {
                kinds++;
                if (kinds > k) {
                    while(l<=r) {
                        cnt[s[l]]--;
                        if(cnt[s[l]] == 0) {
                            kinds--;
                            l++;
                            break;
                        }
                        l++;
                    }
                }
            }
            cnt[s[r]]++;
            r++;

            ans = max(ans, r - l);
        }

        return ans;
    }
};