class Solution {
public:

    int countDigitOne(int n) {
       if (n <= 0) return 0;

       string s = to_string(n); // 5314
       int high = s[0] - '0'; // 5
       int remain = n - high * pow(10, s.size() - 1); // 5 - 5 * 1000
       int smaller = pow(10, s.size() - 1) - 1; // 999

       if (high == 1) {
           return remain + 1 + countDigitOne(remain) + countDigitOne(smaller);
       } else {
           return countDigitOne(remain) + countDigitOne(smaller) * high + (smaller + 1);
       }
    }
};