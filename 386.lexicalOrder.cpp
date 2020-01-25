class Solution {
public:    
    inline int to_int(string s) {
        int ans = 0;
        for (auto c: s) {
            ans *= 10;
            ans += c - '0';
        }

        return ans;
    }

    vector<int> lexicalOrder(int n) {
       vector<string> s;
       for (int i = 1; i <= n; i++) {
           s.push_back(to_string(i));
       } 

       sort(s.begin(), s.end());
       vector<int> ans;

       for (int i = 0; i < n; i++) {
           ans.push_back(to_int(s[i]));
       }

       return ans;
    }
};