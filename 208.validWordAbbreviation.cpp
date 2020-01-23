class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int pw = 0;
        int pa = 0;

        while(pa<abbr.size() && pw<word.size()) {
            if (abbr[pa] == '0') return false;
            if (abbr[pa]>'0' && abbr[pa]<='9') {
                int num = 0;
                while(pa<abbr.size() && abbr[pa]>='0' && abbr[pa]<='9') {
                    num *= 10;
                    num += abbr[pa] - '0';
                    pa++;
                }
                for(int i=0; i<num; i++) {
                    pw++;
                }
            } else {
                if (abbr[pa] != word[pw]) return false;
                pa++;
                pw++;
            }
        }

        if (pa != abbr.size() || pw != word.size()) return false;

        return true;
    }
};