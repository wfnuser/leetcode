class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        if (target <= 2) return ans;

        if (target == 3) {
            ans.push_back(vector<int>{1,2});
            return ans;
        }

        for (int i = sqrt(2*target); i >= 2; i--) {
            if (2*target % i == 0) {
                if ((2*target / i + 1 - i) %2 != 0) continue;
                int start = (2*target / i + 1 - i) / 2;
                if (start < 0) continue;
                vector<int> tmp;

                for (int j = start; j < start + i; j++) {
                    tmp.push_back(j);
                }

                ans.push_back(tmp);
            }
        }

        return ans;
    }
};