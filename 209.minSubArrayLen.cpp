/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (40.69%)
 * Likes:    170
 * Dislikes: 0
 * Total Accepted:    24.1K
 * Total Submissions: 59.1K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
 * 
 * 示例: 
 * 
 * 输入: s = 7, nums = [2,3,1,2,4,3]
 * 输出: 2
 * 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 * 
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        
        int slow = 0;
        int fast = 0;
        int ans = INT_MAX;
        int sum = 0;
        int flag = 1;

        while(fast<size) {
            if (flag) {
                sum += nums[fast];
                fast++;
                if (sum >= s) {ans = min(ans, fast-slow);}
                if (sum > s) {flag = 0;}
            } else {
                sum -= nums[slow];
                slow++;
                if (sum >= s) {ans = min(ans, fast-slow);}
                if (sum < s) {flag = 1;}
                if (slow >= fast) {flag = 1;}
            }
        }

        while(slow < fast && sum >= s) {
            sum -= nums[slow];
            slow++;
            if (sum >= s) {ans = min(ans, fast-slow);}
        }

        if (ans == INT_MAX) return 0;

        return ans;
    }
};
// @lc code=end

