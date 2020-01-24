class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans = "";
        int cnt = 0;
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] == '-') {
                continue;
            } else {
                cnt++;
                if(S[i] >= 'a'&&S[i] <= 'z') {
                    S[i] -= 32;
                }
                ans += S[i];
                if (cnt == K) {
                    ans += '-';
                    cnt = 0;
                }
            }
        }

        while (!ans.empty() && ans.back() == '-') ans.pop_back();
    
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};