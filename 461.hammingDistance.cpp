class Solution {
public:
    int hammingDistance(int x, int y) {
        int num = 0;
        for (int i = 0; i < 31; i++) {
            int a = x & 1;
            int b = y & 1;
            if (a != b) num++;
            x=x>>1;
            y=y>>1;
        }

        return num;
    }
};