class Solution {
public:
    int calculate(string s) {
        int x = 1;
        int y = 0;
        for (auto c: s) {
            if (c == 'A') {
                x = 2 * x + y;
            } else {
                y = 2 * y + x;
            }
        }
        return x + y;
    }
};