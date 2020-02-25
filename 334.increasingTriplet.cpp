class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> v;

        for (int i = 0; i < nums.size(); i++) {
            if (v.size() == 0) {
                v.push_back(nums[i]);
                continue;
            } else if(v.size() == 1) {
                if (nums[i] > v[0]) {
                    v.push_back(nums[i]);
                    continue;
                }
                v[0] = min(v[0], nums[i]);
            } else {
                if (nums[i] > v[1]) {
                    return true;
                }
                if (nums[i] == v[1]) continue;
                if (nums[i] < v[1]) {
                    if (nums[i] > v[0]) {
                        v[1] = nums[i];
                    } else if (nums[i] < v[0]) {
                        v[0] = nums[i];
                    }
                }
            }
            if (v.size() == 3) return true;
        }

        return false;
    }
};