class Solution {
public:
    string multiply(string num1, string num2) {
        int ans[250] = {0};
        string str="";
        if (num1.size() == 1 && num1[0] == '0') return "0";
        if (num2.size() == 1 && num2[0] == '0') return "0";

        for (int i = 0; i < num1.size(); i++) {
            for (int j = 0; j < num2.size(); j++) {
                int product = (num1[num1.size()-i-1] - '0') * (num2[num2.size()-1-j] - '0');
                ans[i+j] += product%10;
                ans[i+j+1] += product/10;

                ans[i+j+1] += ans[i+j] / 10;
                ans[i+j+2] += ans[i+j+1] / 10;

                ans[i+j] %= 10;
                ans[i+j+1] %= 10;
            }
        }
        int i = 249;
        while(i>=0&&ans[i] == 0) {i--;};

        for (int j = i; j >= 0; j--) {
            str += to_string(ans[j]);
        }

        return str;
    }
};