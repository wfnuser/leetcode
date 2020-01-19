class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> lookup;
        for (auto num: nums) {
            if (lookup.find(num) != lookup.end()) {
                return true;
            }
            lookup.insert(num);
        }
        return false;
    }
};