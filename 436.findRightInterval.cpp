class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> left;
        vector<pair<int, int>> right;

        unordered_map<int, int> smallestInterval;

        for (int i = 0; i < intervals.size(); i++) {
            left.push_back(make_pair(intervals[i][0], i));
            right.push_back(make_pair(intervals[i][1], i));    
        }

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        int l = 0;
        int r = 0;
        int N = intervals.size();
        vector<int> ans;

        while(l<N) {
            if (left[l].first >= right[r].first) {
                smallestInterval[right[r].first] = left[l].second;
                r++;
            } else {
                l++;
            }
        }

        for (int i = 0; i < intervals.size(); i++) {
            if (smallestInterval.find(intervals[i][1]) == smallestInterval.end()) {
                ans.push_back(-1);
            } else {
                ans.push_back(smallestInterval[intervals[i][1]]);
            }
        }

        return ans;
    }
};