// REFER TO: https://blog.csdn.net/fuxuemingzhu/article/details/101201253 
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        const int N = colors.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < N; ++i) {
            m[colors[i]].push_back(i);
        }
        vector<int> res;
        for (auto& query : queries) {
            int cur = INT_MAX;
            int target = query[0];
            if (!m.count(query[1])) {
                res.push_back(-1);
                continue;
            }
            int pos = closest(m[query[1]], target);
            res.push_back(abs(pos - target));
        }
        return res;
    }
    int closest(vector<int>& nums, int target) {
        int pos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (pos == 0) return nums[0];
        if (pos == nums.size()) return nums[nums.size() - 1];
        if (nums[pos] - target < target - nums[pos - 1])
            return nums[pos];
        return nums[pos - 1];
    }
};


