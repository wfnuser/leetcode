class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;

        unordered_map<int, int> charmap;

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            for (char c: word) {
                charmap[i] |= 1 << (c-'a');
            }
        }

        for (int i = 0; i < words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                if ((charmap[i]&charmap[j]) == 0) {
                    ans = max(ans, (int)(words[i].length()*words[j].length()));
                }
            }
        }

        return ans;
    }
};