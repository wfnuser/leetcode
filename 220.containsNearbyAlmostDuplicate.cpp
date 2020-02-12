class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> S;

        for (int i = 0; i < nums.size(); i++) {
            auto index = S.lower_bound((long)nums[i]-t);
            if (index != S.end() && *index <= (long)nums[i]+t) return true;
            S.insert(nums[i]);

            if (S.size() > k) {
                S.erase(nums[i-k]);
            }
        }

        return false;
    }
};