class Solution {
public:
    vector<string> res;

    void dfs(string s, string ip, int cnt) {
        if (cnt == 4 && s == "") res.push_back(ip);

        int seg = 0;
        for (int i = 0; i < 4; i++) {
            seg *= 10;
            seg += s[i]-'0';

            if (seg > 255) break;
            if (to_string(seg).size() != i+1) break;

            string newIp = ip + to_string(seg);
            if (cnt != 3) newIp += '.';
            if (i+1 > s.size()) break;
            dfs(s.substr(i+1, s.size()-i-1), newIp, cnt+1);
        }

    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) return res;
        dfs(s, "", 0);
        return res;
    }
};