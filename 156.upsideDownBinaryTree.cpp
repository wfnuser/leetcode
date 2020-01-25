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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL || root->left == NULL) return root;
        auto l = root->left;
        auto r = root->right;
        root->left = NULL;
        root->right = NULL;
        auto res = upsideDownBinaryTree(l);
        l->left = r;
        l->right = root;
        return res;
    }
};