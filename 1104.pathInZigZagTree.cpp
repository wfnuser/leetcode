class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int tmp = label;
        int level = 0;

        int left = 1;
        while(tmp >= 1) {
            tmp /= 2;
            level++;
            left=left*2;
        }
        left /= 2;

        vector<int> ans;

        if (level % 2 == 0) {
            label = left + (left * 2 - label) - 1;
        }

        while(level) {
            if (level % 2 == 0) {
                label = left + (left * 2 - label) - 1;
            }
            ans.push_back(label);
            if (level % 2 == 0) {
                label = left + (left * 2 - label) - 1;
            }
            label /= 2;
            left /= 2;
            level--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
