class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int fre = 0;
        int ans = INT_MAX;
        unordered_map<int, int> cnt;
        unordered_map<int, int> first;
        unordered_map<int, int> end;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            cnt[num]++;
            if (cnt[num] == 1) {
                first[num] = i;
            }
            end[num] = i;
            if (cnt[num] >= fre) {
                fre = cnt[num];
            }
        }

        for (auto p : cnt) {
            if (p.second == fre) {
                ans = min(ans, (end[p.first] - first[p.first] + 1));
            }
        }

        return ans;
    }
};
