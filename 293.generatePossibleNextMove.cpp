class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        if (s.size() <= 1) return ans;

        for (int i = 1; i<s.size(); i++) {
            if (s[i] == '+' && s[i-1] == '+') {
                string ss = s;
                ss[i] = '-';
                ss[i-1] = '-';
                ans.push_back(ss);
            }
        }   
        
        return ans;
    }
};