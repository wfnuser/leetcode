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

    bool isValid(TreeNode* root, long upper, long lower) {
        if (root == NULL) return true;
        if (root->val >= upper || root->val <= lower) return false;

        return isValid(root->left, root->val, lower) && isValid(root->right, upper, root->val);
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        return isValid(root->left, (long)root->val, INT_MIN-1L) && isValid(root->right, INT_MAX+1L, (long)root->val);
    }
};