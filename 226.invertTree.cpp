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

    void invert(TreeNode* root) {
        if (root == NULL) return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = right;
        root->right = left;

        invert(root->left);
        invert(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};