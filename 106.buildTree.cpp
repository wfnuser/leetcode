/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        int size = postorder.size();
        int last = postorder[size-1];

        vector<int> left;
        vector<int> right;
        int flag = 0;

        for (auto num: inorder) {
            if (num == last) {flag = 1; continue;}
            if (flag == 0) left.push_back(num);
            else right.push_back(num);
        }
        postorder.pop_back();

        TreeNode* root = new TreeNode(last);
        root->right = buildTree(right, postorder);
        root->left = buildTree(left, postorder);

        return root;
    }
};
// @lc code=end

