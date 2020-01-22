class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> sm;
        unordered_map<char, int> tm;
        
        for (auto c:s) {
            sm[c]++;
        }
        for (auto c:t) {
            tm[c]++;
        }

        for (auto c:tm) {
            if (sm[c.first] < c.second) {
                return c.first;
            }
        }

        return ' ';
    }
};