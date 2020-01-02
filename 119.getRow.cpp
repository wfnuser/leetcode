class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        if (rowIndex == 0) return ans;
        ans.push_back(1);
        if (rowIndex == 1) return ans;

        for (int i = 2; i <= rowIndex; i++) {
            ans.insert(ans.begin(), 0);
            for (int j = 0; j<i; j++) {
                ans[j] = ans[j] + ans[j+1];
            }
            ans[i] = 1;
        }

        return ans;
    }
};