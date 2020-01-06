/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (36.41%)
 * Likes:    345
 * Dislikes: 0
 * Total Accepted:    29.6K
 * Total Submissions: 81.3K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给定一个整数数组
 * nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
 *
 * 示例 1:
 *
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 *
 *
 * 示例 2:
 *
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 *
 */

// @lc code=start
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        vector<int> minP;
        vector<int> maxP;
        
        minP.push_back(nums[0]);
        maxP.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            int s = nums[i];
            int l = nums[i];

            if (nums[i] * minP[i-1] > l) l = nums[i] * minP[i-1];
            if (nums[i] * maxP[i-1] > l) l = nums[i] * maxP[i-1];
            if (nums[i] * minP[i-1] < s) s = nums[i] * minP[i-1];
            if (nums[i] * maxP[i-1] < s) s = nums[i] * maxP[i-1];

            minP.push_back(s);
            maxP.push_back(l);
        }

        int ans = INT_MIN;

        for (auto num: maxP) {
            ans = max(num, ans);
        }

        return ans;
    }
};
// @lc code=end
