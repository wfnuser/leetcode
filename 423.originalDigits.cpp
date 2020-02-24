class Solution {
public:
    unordered_map<char, int> cnt;
    string res = "";

    string originalDigits(string s) {
        for (auto ch: s) {
            cnt[ch]++;
        }
        
        map<int, int> num;
        num[0] = cnt['z'];
        num[2] = cnt['w'];
        num[4] = cnt['u'];
        num[6] = cnt['x'];
        num[8] = cnt['g'];

        num[7] = cnt['s'] - num[6];
        num[5] = cnt['f'] - num[4];
        num[3] = cnt['r'] - num[4] - num[0];
        num[9] = cnt['i'] - num[5] - num[6] - num[8];
        num[1] = cnt['o'] - num[2] - num[4] - num[0];

        for (int i = 0; i <= 9; i++) {
            if (num[i]) {
                for (int j = 0; j < num[i]; j++) {
                    res += to_string(i);
                }
            }
        }

        return res;
    }
};