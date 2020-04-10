class Solution {
   public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        string ss = "";
        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        ss = s.substr(i);
        if (ss.size() == 0) return "";
        while (ss[ss.size() - 1] == ' ') {
            ss.pop_back();
        }
        s = ss;
        ss = "";
        for (int i = 0; i < s.size(); i++) {
            ss.push_back(s[i]);
            if (s[i] == ' ') {
                while (i < s.size() && s[i] == ' ') i++;
                i--;
            }
        }

        int l = 0;
        for (int i = 0; i < ss.size(); i++) {
            if (ss[i] == ' ') {
                reverse(ss.begin() + l, ss.begin() + i);
                l = i + 1;
            }
        }
        reverse(ss.begin() + l, ss.begin() + ss.size());

        return ss;
    }
};