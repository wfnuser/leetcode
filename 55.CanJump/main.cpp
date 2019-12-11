class Solution {
public:
    bool canJump(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        int size = nums.size();
        if (size <= 1) return true;
        while(slow <= fast && fast < size - 1) {
            if (slow == fast && nums[slow] == 0) return false;
            int jump = nums[slow];
            if (slow + jump > fast) fast = slow + jump;
            slow++;
        }
        return true;
    }
};
