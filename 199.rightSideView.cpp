/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (62.43%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    14.9K
 * Total Submissions: 23.8K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
 * 示例:
 * 
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 * 解释:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
 * 
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
    vector<int> ans;

    void dfs(TreeNode* root, int level) {
        if (root == NULL) return;
        if (ans.size() < level + 1) {
            ans.push_back(0);
        }
        ans[level] = root->val;
        if (root->left) dfs(root->left, level+1);
        if (root->right) dfs(root->right, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
// @lc code=end

