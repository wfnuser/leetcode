class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> cp;
        vector<int> ans;
        int sum = 0;

        for (auto c: p) {
            cp[c]++;
            sum++;
        }

        if (s.size() < p.size()) return ans;

        int start = 0;
        int end = 0;

        for (end = 0; end < p.size(); end++) {
            if (cp[s[end]] > 0) {
                sum--;
            }
            cp[s[end]]--;
        }
        if (sum == 0) ans.push_back(0);
        
        end = p.size() - 1;
        while(end+1 < s.size()) {
            end++;
            if (cp[s[start]]>=0) {
                sum++;
            }
            cp[s[start]]++;
            if (cp[s[end]]>0) {
                sum--;
            }
            cp[s[end]]--;
            start++;
            if (sum == 0) ans.push_back(start);
        }

        return ans;
    }
};