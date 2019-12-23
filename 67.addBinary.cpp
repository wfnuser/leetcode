class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length()>b.length()) return addBinary(b,a);
        int carry = 0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        for (int i=0; i<a.length(); i++) {
            int x = a[i] - '0';
            int y = b[i] - '0';

            int sum = x + y + carry;
            carry = sum / 2;
            sum %= 2;

            b[i] = '0' + sum;
        }

        for (int i=a.length(); i<b.length(); i++) {
            int x = b[i] - '0';
            int sum = x + carry;
            carry = sum / 2;
            sum %= 2;
            b[i] = '0' + sum;
        }

        if (carry) b += ('0'+carry);
        reverse(b.begin(), b.end());

        return b;
    }
};