class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;

        for (auto num: nums) {
            map[num]++;
            if (map[num] > nums.size() / 2) return num;
        }
        
        return 0;
    }
};