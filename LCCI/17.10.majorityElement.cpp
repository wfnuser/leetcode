class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0;
        int target = -1;

        for (auto num: nums) {
            if (num == target) {
                major++;
            } else {
                major--;
            }
            if (major <= 0) {
                major = -major;
                target = num;
            }
        }

        int cnt = 0;
        for (auto num: nums) {
            if (num == target) cnt++;
        }

        return cnt * 2 >= nums.size() ? target : -1;
    }
};
