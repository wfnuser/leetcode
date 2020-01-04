class Solution {
public:

    bool isPalindrome(string s, int l, int r) {
        if (l > r) return false;
        while(l<r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    vector<vector<string>> helper(string s, int l, int r) {
        vector<vector<string>> ans;
        if (l>r) return ans;
        if (l==r) {
            string tmp(1,s[l]);
            vector<string> partition(1, tmp);
            ans.push_back(partition);
            return ans;
        }
        for (int i = l; i < r; i++) {
            if (isPalindrome(s, l, i)) {
                string tmp = s.substr(l, i-l+1);
                for (auto com: helper(s, i+1, r)) {
                    com.insert(com.begin(), tmp);
                    ans.push_back(com);
                }
            }
        }
        if (isPalindrome(s, l, r)) {
            vector<string> partition(1, s.substr(l, r-l+1));
            ans.push_back(partition);
        }
        return ans;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        return helper(s, 0, s.size() - 1);
    }
};