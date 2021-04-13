class Solution {
public:

    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        int tmp = 0;
        for (auto c: s) {
            if (c == ' ') continue;
            if (c >= '0' && c <= '9') {
                tmp *= 10;
                tmp += c - '0';
                continue;
            }
            if (!op.empty()) {
                if (op.top() == '/') {
                    tmp = num.top() / tmp;
                    num.pop();
                    op.pop();
                } else if (op.top() == '*') {
                    tmp = num.top() * tmp;
                    num.pop();
                    op.pop();
                }
            }
            op.push(c);
            num.push(tmp);
            tmp = 0;
        }

        if (op.empty()) return tmp;
        
        if (op.top() == '*') {
            tmp = num.top() * tmp;
            op.pop();
            num.pop();
        } else if (op.top() == '/') {
            tmp = num.top() / tmp;
            op.pop();
            num.pop();
        }
        
        if (op.empty()) return tmp;

        int sum = 0;
        while (!op.empty()) {
            if (op.top() == '+') {
                sum += tmp;
            }
            if (op.top() == '-') {
                sum -= tmp;
            }
            tmp = num.top();
            op.pop();
            num.pop();
        }

        return sum+tmp;
    }
};