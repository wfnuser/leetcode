class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == 0) return "0";
        if (num.size() == 1) {
            if (k == 0) return num;
            if (k >= 1) return "0";
        }

        int K = k;
        int cntNonZero = 0;
        int lastIndex = -1;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] != '0') cntNonZero++;
            if (num[i] == '0') {
                if(cntNonZero <= K) {
                    K -= cntNonZero;
                    cntNonZero = 0;
                    lastIndex = i;
                } else {
                    break;
                }
            }
        }

        if (lastIndex == num.size() - 1) return "0";
        if (lastIndex != -1) {
            num = num.substr(lastIndex+1, num.size() - lastIndex);
        }

        stack<char> S;
        S.push(num[0]);
        for (int i = 1; i < num.size(); i++) {
            if (K <= 0) {
                S.push(num[i]);
                continue;
            }
            if (num[i] < S.top()) {
                while(!S.empty() && num[i] < S.top()) {
                    S.pop();
                    K--;
                    if (K <= 0) break;
                }
                S.push(num[i]);
            } else {
                S.push(num[i]);
            }
        }

        string ans = "";
        while(!S.empty()) {
            if (K > 0) {
                K--;
                S.pop();
                continue;
            }
            ans = S.top() + ans;
            S.pop();
        }
        if (ans == "") return "0";
        return ans;
    }
};