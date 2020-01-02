/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* vectorToTree(vector<int>& nums, int left, int right) {
        if (left>right) return NULL;
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = vectorToTree(nums, left, mid-1);
        root->right = vectorToTree(nums, mid+1, right);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return NULL;
        return vectorToTree(nums,0,size-1);
    }
};
// @lc code=end

