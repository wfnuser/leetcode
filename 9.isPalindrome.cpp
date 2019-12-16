class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x==0) return true;
        string s = "";
        while(x>0) {
            s += to_string(x%10);
            x /= 10;
        }
        if (s.size() == 1) return true;
        for (int i=0; i<=(s.size()-1)/2; i++) {
            if (s[i]!=s[s.size()-i-1]) return false;
        }
        return true;
    }
};