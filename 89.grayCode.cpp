class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return vector<int>(1, 0);
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        int prod = 2;
        for (int i = 1; i<n; i++) {
            int prevSize = ans.size();
            for (int j = prevSize - 1; j>=0; j--) {
                ans.push_back(ans[j]+prod);
            }
            prod *= 2;
        }
        return ans;
    }
};