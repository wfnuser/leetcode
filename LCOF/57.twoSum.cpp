class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                ans = vector<int>{nums[left], nums[right]};
                return ans;
            }
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                left++;
            }
        }
        return ans;
    }
};