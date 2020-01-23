class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) return addStrings(num2, num1);

        string ans;
        int carry = 0;
        int i = 0;

        for (i = 0; i < num2.size(); i++) {
            int n1 = num1[num1.size()-1-i] - '0';
            int n2 = num2[num2.size()-1-i] - '0';

            int n = n1 + n2 + carry;

            if (n>=10) carry = 1;
            else carry = 0;

            n = n % 10;

            ans = to_string(n) + ans;
        }
        if (i < num1.size()) {
            while(i<num1.size()) {
                int n = num1[num1.size()-1-i] - '0' + carry;
                if (n>=10) carry = 1;
                else carry = 0;

                ans = to_string(n%10) + ans;
                i++;
            }
        }
        if (carry >= 1) {
            ans = to_string(carry) + ans;
        }

        return ans;
    }
};