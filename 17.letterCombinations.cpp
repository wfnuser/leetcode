string s[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
    vector<string> ans;
    
    void search(string res, int pos, string digits) {
        if (pos>=digits.size()) { 
            ans.push_back(res);
            return;
        }
        int num = digits[pos] - '2';
        string options = s[num];
        for (int i = 0; i < options.size(); i++) {
            search(res+options[i], pos+1, digits);
        }
    }

    vector<string> letterCombinations(string digits) {
        int pos = 0;
        int size = digits.size();
        if (size == 0) return ans;

        search("", pos, digits);

        return ans;
    }
};