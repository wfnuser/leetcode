class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int ans = 0;

        for (auto num: nums) {
            cnt[num]++;
            if (cnt[num-1]) ans = max(ans, cnt[num-1]+cnt[num]);
            if (cnt[num+1]) ans = max(ans, cnt[num+1]+cnt[num]);
        }

        return ans;
    }
};