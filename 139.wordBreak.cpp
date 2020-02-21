class Solution {
public:
    unordered_map<int, int> m;

    bool wordBreak(string s, vector<string>& wordDict) {
        queue<int> Q;
        Q.push(0);

        while(!Q.empty()) {
            int start = Q.front();
            Q.pop();

            for (auto word: wordDict) {
                int len = word.size();
                if (start+len-1>=s.size()) continue;

                string ss = s.substr(start, len);
                if (ss == word) {
                    if (start+len == s.size()) return true;
                    if (!m[start+len]) {
                        m[start+len]++;
                        Q.push(start+len);
                    }
                }
            }
        }
        
        return false;
    }
};