// 这道题是一个非常有价值的教训
// string s;
// s += 'x' 和 s = 'x' + s的时空效率都是完全不同的
// 一开始是直接 s = 'x' + s这样写 时间不一定超 但是空间告诉我超了
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