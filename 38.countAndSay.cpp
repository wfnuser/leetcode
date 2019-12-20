class Solution {
public:
    string countAndSay(int n) {
        string ans;
        if (n == 0) return "";
        ans = "1";
        for (int i=2; i<=n; i++) {
            string tmp = "";
            int j = 0;
            while (j<ans.size()) {
                int cnt = 0;
                char c = ans[j];
                while(ans[j]==c&&j<ans.size()) {cnt++;j++;}
                tmp += to_string(cnt)+c;
            }
            ans = tmp;
        }
        return ans;
    }
};