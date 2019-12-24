class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 2) return nums.size();

        int slow = 1;
        int fast = 2;
        int cnt = 1;
        if (nums[0] == nums[1]) cnt = 2;

        while(fast < size) {
            if (nums[fast] != nums[fast-1]) {
                slow++;
                nums[slow] = nums[fast];
                fast++;
                cnt = 1;
            } else {
                if (cnt == 2) fast++;
                else {
                    cnt++;
                    slow++;
                    nums[slow] = nums[fast];
                    fast++;
                }
            }
        }

        return slow+1;
    }
};