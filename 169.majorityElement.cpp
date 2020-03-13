class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int last = nums[0];
        int cnt = 0;

        for (auto num: nums) {
            if (num == last) cnt++;
            else {
                cnt--;
                if (cnt < 0) {
                    cnt = 0;
                    last = num;
                } 
            }
        }

        return last;
    }
};