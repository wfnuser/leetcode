class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string>> middle;
        vector<string> ans;

        int length = 0;
        vector<string> tmp;
        for (auto word: words) {
            length += word.size();
            if (length > maxWidth) {
                length = word.size();
                middle.push_back(tmp);
                tmp = vector<string>(0);
            }
            tmp.push_back(word);
            length++;
        }

        if (!tmp.empty()) {
            middle.push_back(tmp);
        }

        string line;
        
        for (int w = 0; w < middle.size() - 1; w++) {
            vector<string> words = middle[w];
            int cnt = words.size();
            if (cnt == 1) {
                line += words[0];
                while (line.size() != maxWidth) {
                    line += " ";
                }
            } else {
                int sum = 0;
                for (auto word: words) {
                    sum += word.size();
                }
                int spaces = maxWidth - sum;
                int space = spaces / (cnt - 1);
                int remain = spaces - space * (cnt - 1);

                string blank = "";
                for (int i = 0; i < space; i++) {
                    blank += " ";
                }

                for (int i = 0; i < remain; i++) {
                    line += words[i];
                    line += blank;
                    line += " ";
                }
                for (int i = remain; i < cnt-1; i++) {
                    // line += words[i];
                    line += words[i];
                    line += blank;
                }
                line += words[cnt-1];
            }
            ans.push_back(line);
            line = "";
        }

        for (auto word: middle[middle.size()-1]) {
            line += word;
            line += " ";
        }
        if (line.size() > maxWidth) {
            line.pop_back();
        }
        while(line.size()<maxWidth) {
            line += " ";
        }
        ans.push_back(line);

        return ans;
    }
};
