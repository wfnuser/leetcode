class Solution {
public:
    string decodeString(string s) {
        string tmp = "";
        stack<int> S;
        stack<string> SS;
        int i = 0;
        int num = 0;
        while(i < s.size()) {
            if (s[i] <= '9' && s[i] >= '0') {
                SS.push(tmp);
                tmp = "";
            }
            while(s[i] <= '9' && s[i] >= '0') {
                num *= 10;
                num += s[i] - '0';
                i++;
            }
            if (s[i] == '[') {
                S.push(num);
                num = 0;
                i++;
            }

            while((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A')) {
                tmp += s[i];
                i++;
            }
            if (s[i] == ']') {
                int times = S.top();
                S.pop();
                string t = "";
                for (int i = 0; i < times; i++) {
                    t += tmp;
                }
                tmp = SS.top() + t;
                SS.pop();
                i++;
            }
        }
        
        return tmp;
    }
};