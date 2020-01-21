class Solution {
public:
    vector<vector<int>> helper(int n, int s) {
        vector<vector<int>> ans;
        
        for (int i = s; i*i <= n; i++) {
            if (n % i == 0) {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(n/i);
                ans.push_back(tmp);

                for (auto v: helper(n/i, i)) {
                    v.insert(v.begin(), i);
                    ans.push_back(v);
                }
            }
        }

        return ans;
    }

    vector<vector<int>> getFactors(int n) {
        return helper(n, 2);
    }
};