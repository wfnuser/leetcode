class Solution {
public:
    string s;
    unordered_map<int, int> m;

    int dfs(int start) {
        if (m[start]) return m[start];
        if (start == s.size()-1) {
            return 1;
        }
        if (start == s.size() - 2) {
            if (s[start] == '1' || (s[start] == '2' && s[start+1] <= '5')) {
                m[start] = 2;                
                return 2;
            }
            m[start] = 1;
            return 1;
        }

        if (s[start] == '1' || (s[start] == '2' && s[start+1] <= '5')) {
            m[start] = dfs(start+1) + dfs(start+2);                
            return m[start];
        }
        
        m[start] = dfs(start+1);
        return m[start];
    }

    int translateNum(int num) {
        s = to_string(num);
        return dfs(0);
    }
};