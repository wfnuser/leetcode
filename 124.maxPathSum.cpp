/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (38.68%)
 * Likes:    279
 * Dislikes: 0
 * Total Accepted:    21.1K
 * Total Submissions: 54.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int maxN = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            if (root->val > maxN) maxN = root->val;
            int l = max(dfs(root->left),0);
            int r = max(dfs(root->right),0);
            if (l+r+root->val > ans) ans = l+r+root->val;
            return max(l, r) + root->val;
        }
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        if (maxN < 0) return maxN;
        return ans;
    }
};
// @lc code=end

