/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 *
 * https://leetcode-cn.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (65.42%)
 * Likes:    280
 * Dislikes: 0
 * Total Accepted:    25.1K
 * Total Submissions: 38.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中
 * output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
 *
 * 示例:
 *
 * 输入: [1,2,3,4]
 * 输出: [24,12,8,6]
 *
 * 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
 *
 * 进阶：
 * 你可以在常数空间复杂度内完成这个题目吗？（
 * 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
 *
 */

// @lc code=start
class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int product2 = 1;
        int cnt = 0;
        for (auto num : nums) {
            if (num == 0) {cnt++;}
            else product *= num;
            product2 *= num;
        }
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if (cnt >= 2) {*it = 0;}
            else {
                if (*it == 0) {
                    *it = product;
                } else {
                    *it = product2 / *it;
                }
            }
        }

        return nums;
    }
};
// @lc code=end
