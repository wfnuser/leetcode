class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int last = 0;

        reverse(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin()+last, s.begin()+i);
                while(s[i] == ' ' && i < s.size()) i++;
                last = i;
                i--;
            }
        }
        if (last != s.size()) {
            reverse(s.begin()+last, s.end());
        }

        last = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                string tmp = s.substr(last, i - last);
                ans += tmp + ' ';
                while(s[i] == ' ' && i < s.size()) i++;
                last = i;
                i--;
            }
        }
        if (last != s.size()) {
            string tmp = s.substr(last, s.size() - last);
            ans += tmp;
        }

        if (ans.size() == 0) return ans;
        int p = 0;
        int e = ans.size() - 1;
        while(ans[p] == ' ') p++;
        while(ans[e] == ' ') e--;

        if (p > e) return "";

        ans = ans.substr(p, e - p + 1);
        return ans;
    }
};