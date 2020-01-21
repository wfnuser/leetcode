class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int last = 0;
        int lastIndex = -1;
        int ans = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (word2 == words[i]) {
                if (last && words[lastIndex] == word1) {ans = min(ans, i - lastIndex);}
                last = 2;                
                lastIndex = i;
            }
            if (word1 == words[i]) {
                if (last && words[lastIndex] == word2) {ans = min(ans, i - lastIndex);}
                last = 1;                
                lastIndex = i;
            }
        }
        return ans;
    }
};