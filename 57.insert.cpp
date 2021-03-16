class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> res;

        for (i = 0; i < intervals.size(); i++) {
            if (newInterval[0] <= intervals[i][1]) {
                break;
            }
            res.push_back(intervals[i]);
        }

        int j = i;
        for (j = i; j< intervals.size(); j++) {
            if (newInterval[1] < intervals[j][0]) {
                break;
            }
            newInterval[0] = min(intervals[j][0], newInterval[0]);
            newInterval[1] = max(intervals[j][1], newInterval[1]);
        }
        res.push_back(newInterval);

        for (int i = j; i < intervals.size(); i++) {
            res.push_back(intervals[i]);
        }

        return res;
    }
};