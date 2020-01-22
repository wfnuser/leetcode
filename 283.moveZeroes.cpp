class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int slow = 0;
        int fast = 1;

        while (fast < size) {
            while(fast < size && nums[fast] == 0) {fast++;}
            if (fast >= size) break;
            while(slow < fast && nums[slow] != 0) {slow++;}
            if (slow >= fast) {slow++;fast++;continue;}

            int tmp = nums[slow];
            nums[slow] = nums[fast];
            nums[fast] = tmp;
        }

    }
};