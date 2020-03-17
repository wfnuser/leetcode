class Solution {
public:
    bool isNum(char c) {
        if (c >= '0' && c <= '9') return true;
        else return false;
    }

    int strToInt(string str) {
        long ans = 0;
        int flag = 1;
        int pos = 0;
        while(pos < str.size() && str[pos] == ' ') {pos++;}
        if (pos >= str.size()) return ans;

        if (str[pos] == '+') {
            flag = 1;
            pos++;
        } else if (str[pos] == '-') {
            flag = -1;
            pos++;
        }
        if (pos >= str.size()) return ans;
        if (!isNum(str[pos])) return ans;

        while(pos<str.size()) {
            if (!isNum(str[pos])) break;
            ans += (str[pos]-'0');
            if ((flag * ans) > INT_MAX) return INT_MAX;
            if ((flag * ans) < INT_MIN) return INT_MIN;
            ans *= 10;
            pos++;
        }
        ans /= 10;

        if (flag * ans > INT_MAX) return INT_MAX;
        if (flag * ans < INT_MIN) return INT_MIN;

        return flag*ans;
    }
};