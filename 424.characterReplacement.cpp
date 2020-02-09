class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;

        int left = 0;
        int right = 0;
        unordered_map<char, int> cnt;
        int maxCnt = 0;

        while(right < s.size()) {
            cnt[s[right]]++;
            maxCnt = max(maxCnt, cnt[s[right]]);

            if (right - left + 1 > k + maxCnt) {
                cnt[s[left++]]--;
            }
            ans = max(ans, right - left + 1);
            
            right++;
        }

        return ans;
    }
};