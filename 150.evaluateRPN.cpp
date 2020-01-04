class Solution {
public:
    bool isOp(string token) {
        if (token == "+" || token == "*" || token == "/" || token == "-") return true;
        return false;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        if (tokens.size() == 0) return 0;

        for (auto token: tokens) {
            if (isOp(token)) {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();

                int res = 0;
                if (token == "+") res = num1+num2;
                if (token == "*") res = num1*num2;
                if (token == "-") res = num2-num1;
                if (token == "/") res = num2/num1;

                s.push(res);
            } else {
                s.push(stoi(token));
            }
        }

        return s.top();
    }
};