/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 *
 * https://leetcode-cn.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (69.77%)
 * Likes:    78
 * Dislikes: 0
 * Total Accepted:    12.4K
 * Total Submissions: 17.8K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9
 * 的正整数，并且每种组合中不存在重复的数字。
 *
 * 说明：
 *
 *
 * 所有数字都是正整数。
 * 解集不能包含重复的组合。 
 *
 *
 * 示例 1:
 *
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 *
 *
 * 示例 2:
 *
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 *
 *
 */

// @lc code=start
class Solution {
   public:
    void solve(vector<vector<int>>& res, vector<int>& path, int k, int n,
               int s) {
        if (k == 0 && n == 0) {
            res.push_back(path);
            return;
        }
        int sum = 0;
        for (int i = s; i <= s + k - 1; i++) {
            sum += i;
        }
        if (sum > n) return;

        for (int i = s; i <= 9; i++) {
            path.push_back(i);
            solve(res, path, k - 1, n - i, i + 1);
            path.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;

        solve(res, path, k, n, 1);

        return res;
    }
};
// @lc code=end
