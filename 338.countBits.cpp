class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        ans[0] = 0;
        if (num == 0) {
            return ans;
        }
        ans[1] = 1;
        if (num == 1) {
            return ans;
        }

        int point = 0;
        for (int i = 2; i <= num; i++) {
            if (!(i&(i-1))) {
                point = 0;
            }
            ans[i] = ans[point]+1;
            point++;
        }

        return ans;
    }
};