class Solution {
public:
    void reverseWords(vector<char>& s) {
        vector<char> ans;
        
        int pre = s.size() - 1;
        for (int i = s.size() - 1; i >=0; i--) {
            if (s[i] == ' ') {
                for (int j = i+1; j<= pre; j++) {
                    ans.push_back(s[j]);
                }
                ans.push_back(' ');
                pre = i-1;
            }
        }

        for (int i = 0; i <= pre; i++) {
            ans.push_back(s[i]);
        }

        s = ans;
    }
};