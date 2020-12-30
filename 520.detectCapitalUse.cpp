class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 0) return true;

        if (word[0] >= 65 && word[0] <= 90) {
            if (word.size() == 1) return true;
            if (word[1] >= 65 && word[1] <= 90) {
                for (int i = 1; i < word.size(); i++) {
                    if (word[i] > 90) return false;
                }
            } else {
                for (int i = 1; i < word.size(); i++) {
                    if (word[i] <= 90) return false;
                }
            }
        } else {
            for (int i = 1; i < word.size(); i++) {
                if (word[i] <= 90) return false;
            }
        }

        return true;
    }
};