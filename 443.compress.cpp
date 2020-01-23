class Solution {
public:
    int compress(vector<char>& chars) {
        int slow = 0;
        int fast = 0;

        chars.push_back(' ');
        int cnt = 1;

        for (int fast = 1; fast < chars.size(); fast++) {
            if (chars[fast] == chars[fast-1]) {
                cnt++;
            } else {
                chars[slow] = chars[fast-1];
                if (cnt == 1) {
                    slow++;
                } else {
                    slow++;
                    string cs = to_string(cnt);
                    for (auto c: cs) {
                        chars[slow] = c;
                        slow++;
                    }
                }
                cnt=1;
            }
        }
        
        return slow;
    }
};