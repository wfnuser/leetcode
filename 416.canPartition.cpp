class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num: nums) {
            sum += num;
        }
        if (sum %2 != 0) return false;
        sum = sum / 2;
        unordered_map<int, int> m;

        for (auto num: nums) {
            if (num == sum) return true;
            for (auto p: m) {
                if (num+p.first == sum) return true;
                m[num+p.first] = 1;
            }
            m[num] = 1;
        }

        return false;
    }
};