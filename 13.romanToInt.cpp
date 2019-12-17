class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        int pos = 0;
        int ans = 0;
        unordered_map<string, int> m = {{"I", 1}, {"IV", 4}, {"IX", 9}, {"V", 5}, {"X", 10}, {"XL", 40}, {"XC", 90}, {"L", 50}, {"C", 100}, {"CD", 400}, {"CM", 900}, {"D", 500}, {"M", 1000}};

        while(pos<len) {
            if (pos<len-1) {
                string tmp = s.substr(pos, 2);
                if (m[tmp]) {
                    ans += m[tmp];
                    pos += 2;
                    continue;
                }
            }
            string tmp = s.substr(pos, 1);
            ans += m[tmp];
            pos++;
        }

        return ans;
    }
};