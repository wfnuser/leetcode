class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() == 0) return 0;
        int oneL[s.size()];
        int twoL[s.size()];
        char twoC[s.size()];
        
        oneL[0] = 1;
        twoL[0] = 1;
        twoC[0] = s[0];

        int ans = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) {
                oneL[i] = oneL[i-1] + 1;
                twoL[i] = twoL[i-1] + 1;
                twoC[i] = twoC[i-1];
            } else {
                oneL[i] = 1;
                twoC[i] = s[i-1];
                if(twoC[i-1] == s[i]) {
                    twoL[i] = twoL[i-1] + 1;
                } else {
                    twoL[i] = oneL[i-1] + 1;                    
                }
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (twoL[i] > ans) ans = twoL[i]; 
        }

        return ans;
    }
};