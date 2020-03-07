class Solution {
public:
    int cnt = 0;
    int last = 0;
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        cnt = 1;
        last = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != last) cnt--;
            else cnt++;

            if (cnt < 0) {
                cnt = 1;
                last = nums[i];
            }
        }

        return last;
    }
};