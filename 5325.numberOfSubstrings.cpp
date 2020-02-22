class Solution {
public:
    unordered_map<string, int> dp;
    
    int numberOfSubstrings(string s) {
        int n = s.size();
        
        dp["abc"] = 0;
        dp["ab"] = 0;
        dp["bc"] = 0;
        dp["ca"] = 0;
        dp["a"] = 0;
        dp["b"] = 0;
        dp["c"] = 0;
        
        if (s.size() < 3) return 0;
        
        int abc = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                dp["a"]++;
                dp["ab"] = dp["b"] + dp["ab"];
                dp["ca"] = dp["c"] + dp["ca"];
                dp["abc"] = dp["bc"] + dp["abc"];
                dp["bc"] = 0;
                dp["b"] = 0;
                dp["c"] = 0;
            } else if (s[i] == 'b') {
                dp["b"]++;
                dp["bc"] = dp["c"] + dp["bc"];
                dp["ab"] = dp["a"] + dp["ab"];
                dp["abc"] = dp["ca"] + dp["abc"];
                dp["ca"] = 0;
                dp["a"] = 0;
                dp["c"] = 0;
            } else {
                dp["c"]++;
                dp["ca"] = dp["a"] + dp["ca"];
                dp["bc"] = dp["b"] + dp["bc"];
                dp["abc"] = dp["ab"] + dp["abc"];
                dp["ab"] = 0;
                dp["a"] = 0;
                dp["b"] = 0;
            }
            abc += dp["abc"];
            
        }
        
        return abc;
    }
};