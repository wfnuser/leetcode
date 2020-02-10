class Solution {
public:
    string parseTernary(string expression) {
        stack<string> S;

        int index = 0;
        
        while(true) {
            char tf = expression[index];
            if (tf == 'T') {
                if (index+1 >= expression.size() || expression[index+1] == ':') return "T";
                index++;
                index++;
            } else if (tf == 'F') {
                if (index+1 >= expression.size() || expression[index+1] == ':') return "F";
                int cnt = 0;
                while(true) {
                    index++;
                    if (expression[index] == '?') {
                        cnt++;
                    }
                    if (expression[index] == ':') {
                        cnt--;
                    }
                    if (cnt == 0) {
                        index++;
                        break;
                    }
                }
            } else {
                string ans(1, tf);
                return ans;
            }
        } 

        return "";
    }
};