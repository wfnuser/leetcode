class Solution {
public:
    unordered_map<int, set<int>> yx;

    bool isReflected(vector<vector<int>>& points) {
        if (points.size() == 0) return true;
        int left = INT_MAX;
        int right = INT_MIN;

        for (auto point: points) {
            left = min(point[0], left);
            right = max(point[0], right);

            yx[point[1]].insert(point[0]);
        }

        int sum = left + right;

        for (auto row: yx) {
            for (auto x: row.second) {
                if (row.second.find(sum-x) == row.second.end()) return false;
            }
        }
        
        return true;
    }
};