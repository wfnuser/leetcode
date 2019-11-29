class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len == 0) return 0;
        unordered_set<char> lookup;
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r < len) {
            while(lookup.find(s[r]) != lookup.end()) {
                lookup.erase(s[l]);  
                l++;
            }
            if (ans < r - l + 1) ans = r - l + 1;
            lookup.insert(s[r]);
            r++;
        }

        return ans;
    }
};
