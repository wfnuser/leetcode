class Solution {
public:
    int calculate(string s) {
        string numStr = "";
        stack<int> nums;
        stack<char> ops;
        for(auto c: s) {
            if (c == ' ') continue;
            if (c >= '0' && c <= '9') {
                numStr += c;
            } else {
                int cur = stoi(numStr);
                int curOp = c;

                if (ops.empty()) {
                    ops.push(c);
                    nums.push(cur);    
                } else {
                    if (ops.top() == '*') {
                        int last = nums.top();
                        nums.pop();
                        cur = last * cur;
                        nums.push(cur);
                        ops.pop();
                        ops.push(c);
                    } else if (ops.top() == '/') {
                        int last = nums.top();
                        nums.pop();
                        cur = last / cur;
                        nums.push(cur);
                        ops.pop();
                        ops.push(c);
                    } else {
                        nums.push(cur);
                        ops.push(c);
                    }
                }
                numStr = "";
            }
        }

        stack<int> numsR;
        stack<char> opsR;


        int cur = stoi(numStr);

        if (!ops.empty() && (ops.top() == '*' || ops.top() == '/')) {
            int last = nums.top();
            if (ops.top() == '*') {
                cur = last * cur;
            } else {
                cur = last / cur;
            }
            nums.pop();
            ops.pop();
        }


        numsR.push(cur);
        while(!nums.empty()) {
            numsR.push(nums.top());
            nums.pop();
        }
        while(!ops.empty()) {
            opsR.push(ops.top());
            ops.pop();
        }

        int ans = numsR.top();
        numsR.pop();

        while(!opsR.empty()) {
            if (opsR.top() == '+') {
                ans += numsR.top();
            } else {
                ans -= numsR.top();
            }
            numsR.pop();
            opsR.pop();
        }

        return ans;
    }

};