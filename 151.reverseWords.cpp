class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;

        for (int i = 0; i < s.size(); i++) {
            string tmp = "";
            while(i < s.size() && s[i] != ' ') {
                tmp = tmp + s[i];
                i++;
            }
            if (tmp != "") words.push_back(tmp);
        }

        string ans = "";
        
        for (int i = words.size() - 1; i >= 0; i--) {
            ans = ans + words[i];
            if (i != 0) ans = ans + " ";
        }

        return ans;
    }
};