class Solution {
   public:
    string longestPalindrome(string s) {
        string t = "#";

        for (auto c : s) {
            t += c;
            t += "#";
        }

        int maxRight = -1;
        int center = 0;

        int resLen = 0;
        int resCenter = 0;

        vector<int> p(t.size(), 0);
        for (int i = 0; i < t.size(); i++) {
            p[i] = maxRight > i ? min(p[2 * center - i], maxRight - i) : 1;

            while ((i + p[i]) < t.size() && (i - p[i] >= 0) &&
                   t[i + p[i]] == t[i - p[i]])
                ++p[i];
            p[i]--;

            if (maxRight < (i + p[i])) {
                maxRight = i + p[i];
                center = i;
            }

            if (p[i] > resLen) {
                resLen = p[i];
                resCenter = i;
            }
        }

        string ans = "";

        for (auto c : t.substr(resCenter - resLen, resLen * 2 + 1)) {
            if (c != '#') ans += c;
        }

        return ans;
    }
};