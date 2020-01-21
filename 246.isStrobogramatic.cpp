class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> map;
        map['6'] = '9';
        map['9'] = '6';
        map['0'] = '0';
        map['1'] = '1';
        map['8'] = '8';
        if (num.size() == 0) return true;
        if (num.size() == 1) {
            if (num[0] == '0' || num[0] == '8' || num[0] == '1') {
                return true;
            }
            return false;
        }

        for (int i = 0; i <= num.size()/2; i++) {
            if (map[num[i]] != num[num.size()-1-i]) return false;
        }

        return true;
    }
};