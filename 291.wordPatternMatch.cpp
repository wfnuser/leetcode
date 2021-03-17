class Solution {
   public:
    unordered_map<char, string> char_word;
    unordered_map<string, char> word_char;

    bool wordPatternMatch(string pattern, string s) {
        if (pattern.size() == 0 || s.size() == 0) return false;
        return dfs_backtrace(pattern, 0, s, 0);
    }

    bool dfs_backtrace(string& pattern, int pi, string& s, int si) {
        if (pi >= pattern.size()) return si >= s.size();
        if (si >= s.size()) return false;
        char c = pattern[pi];

        if (char_word.count(c) == 0) {
            for (int i = si; i < s.size(); i++) {
                int cur_word_len = i - si + 1;
                string word = s.substr(si, cur_word_len);
                if (word_char.count(word) == 0) {
                    char_word[c] = word;
                    word_char[word] = c;
                    if (dfs_backtrace(pattern, pi + 1, s, i + 1)) return true;
                    char_word.erase(c);
                    word_char.erase(word);
                }
            }
        } else {
            string word = char_word[c];
            if (si + word.size() <= s.size()) {
                string tmp = s.substr(si, word.size());
                if (word == tmp) {
                    return dfs_backtrace(pattern, pi + 1, s, si + word.size());
                }
                return false;
            }
        }
        return false;
    }
};