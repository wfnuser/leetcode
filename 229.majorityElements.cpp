class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;

        for (auto num: nums) {
            m[num]++;
        }

        vector<int> ans;

        for (auto pair: m) {
            if (pair.second > nums.size() / 3) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};