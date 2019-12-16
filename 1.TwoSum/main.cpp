class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[target - nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end() && i != m[nums[i]]) {
                vector<int> res{i, m[nums[i]]};
                return res;
            }
        }

        return vector<int>();
    }
};
