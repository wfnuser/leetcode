class Solution {
public:
    void sort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int pivot = nums[left];
        int slow = left;
        int fast = left+1;

        while(fast <= right) {
            while (nums[fast] >= pivot) {
                fast++;
                if (fast > right) break;
            }
            if (fast > right) break;
            slow++;
            int tmp = nums[slow];
            nums[slow] = nums[fast];
            nums[fast] = tmp;
            fast++;
        }
        nums[left] = nums[slow];
        nums[slow] = pivot;

        sort(nums, left, slow-1);
        sort(nums, slow+1, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size()-1);
        return nums;
    }
};