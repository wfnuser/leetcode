class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans = "";
        int stack = 0;
        for (int i = 0; i < S.size(); i++) {
            if (stack >= 2 || stack == 1 && S[i] == '(' ) {
                ans += S[i];
            }
            if (S[i] == '(') {
                stack ++;
            } else {
                stack --;
            }
        }
        return ans;
    }
};
