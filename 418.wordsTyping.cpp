class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int col = 0;
        string str = "";
        for (auto word: sentence) {
            str += word + " ";
        }

        int cur = 0;
        for (int i = 0; i < rows; i++) {
            cur += cols;
            if (str[cur%str.size()] == ' ') {
                cur++;
                continue;
            }
            while(cur>0 && str[cur%str.size()] != ' ') cur--;
            cur++;
        }

        return cur/str.length();
    }
};