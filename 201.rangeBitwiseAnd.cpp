/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 *
 * https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (44.35%)
 * Likes:    74
 * Dislikes: 0
 * Total Accepted:    7.2K
 * Total Submissions: 16.3K
 * Testcase Example:  '5\n7'
 *
 * 给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。
 * 
 * 示例 1: 
 * 
 * 输入: [5,7]
 * 输出: 4
 * 
 * 示例 2:
 * 
 * 输入: [0,1]
 * 输出: 0
 * 
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
       if(m==0) return 0;
       while(m<n){
           n&=n-1;
       }
       return n;
    }
};
// @lc code=end

