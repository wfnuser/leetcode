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
    int computeDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int left = computeDepth(root->left);
        int right = computeDepth(root->right);

        if (left == -1 || right == -1) return -1;
        if (abs(left - right) <= 1) return 1 + max(left, right);

        return -1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        if (computeDepth(root) == -1) return false;
        return true;
    }


};