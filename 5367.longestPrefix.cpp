class Solution {
public:
    
    void calNext(string needle, vector<int>& next) {
        next[0] = -1;
        int k = -1;

        for (int q = 1; q < needle.size(); q++) {
            while(k>-1&&needle[q]!=needle[k+1]) {
                k = next[k];
            }
            if (needle[q] == needle[k+1]) {
                k++;
            }
            next[q] = k;
        }
    }
    
    string longestPrefix(string s) {
        vector<int> next(s.size(), -1);
        calNext(s, next);
        
        if (s.size() <= 1) return "";
        

        
        return s.substr(0, next[s.size()-1]+1);
    }
};