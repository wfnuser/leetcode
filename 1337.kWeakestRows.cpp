class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> cnt;

        for (int i = 0; i < mat.size(); i++) {
            int sum = 0;
            for (auto each: mat[i]) {
                sum += each;
            }
            cnt.push_back(make_pair(sum, i));
        }

        sort(cnt.begin(), cnt.end());

        vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(cnt[i].second);
        }

        return res;
    }
};
