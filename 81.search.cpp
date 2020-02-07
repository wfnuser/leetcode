class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return false;
        int left = 0;
        int right = size - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[left]) {
                left++;
                continue;
            }
            if (nums[mid] == nums[right]) {
                right--;
            }

            if (nums[mid] > nums[left]) {
                if (nums[mid] >= target && nums[left] <= target) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] <= target && nums[right] >= target) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};