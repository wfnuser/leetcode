class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        string pre = "";
        int pos = 0;
        int ans = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] != word1 && words[i] != word2) continue;
            if (word1 == words[i]) {
                if (pre == word2) {
                    ans = min(ans, i-pos);
                }
            }
            if (word2 == words[i]) {
                if (pre == word1) {
                    ans = min(ans, i-pos);
                }
            }
            pos = i;
            pre = words[i];
        }

        return ans;
    }
};