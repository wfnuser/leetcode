class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> len(30, 0);
        int i = 0;
        int level = 0;
        int ans = 0;

        while(i<input.size()) {
            if (input[i] == '\n') {
                level = 0;
                i ++;
                continue;
            }
            
            if (input[i] == '\t') {
                while(i < input.size() && input[i] == '\t') {
                    i ++;
                    level++;
                }
                int cnt = 0;
                bool isFile = false;
                while(i < input.size() && input[i] != '\n' && input[i] != '\t') {
                    if (input[i] == '.') {isFile = true;}
                    cnt++;
                    i++;
                }
                len[level] = len[level-1] + cnt + 1;
                if (isFile) ans = max(ans, len[level]);
                continue;
            }

            if (input[i] != '\n' && input[i] != '\t') {
                int cnt = 0;
                bool isFile = false;
                while(i < input.size() && input[i] != '\t' && input[i] != '\n') {
                    if (input[i] == '.') {isFile = true;}
                    i++;
                    cnt++;
                }
                len[level] = cnt;
                if (isFile) ans = max(ans, len[level]);
            }
        }

        return ans;
    }
};