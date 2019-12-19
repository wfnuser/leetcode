/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        if (right<0) return 0;
        while(left<right) {
            if (nums[left] != val) left++;
            else {
                while(right>left && nums[right] == val) right--;
                if (nums[right] != val) {
                    int tmp = nums[left];
                    nums[left]= nums[right];
                    nums[right] = tmp;
                }
            }
        }

        if (nums[left] != val) return left+1;
        else return left;
    }
};
// @lc code=end

