class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, vector<int>> scores;
        for  (auto v: items) {
            scores[v[0]].push_back(v[1]);
        }

        vector<vector<int>> res;
        for (auto [stu, scores] : scores) {
            sort(scores.rbegin(), scores.rend());
            int sum = 0;
            for (auto i = 0; i < 5 && i < scores.size(); i++) {
                sum += scores[i];
            }
            res.push_back({stu, sum / 5});
        }

        sort(res.begin(), res.end(),  [&](const vector<int> & a, const vector<int> & b) {
            return a[0] < b[0];
        });

        return res;
    }
};
