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
    int count(TreeNode* node) {
        if (node == NULL) return 0;
        int level = max(count(node->left), count(node->right))+1;
        node->val = level;
        return level;
    }

    bool dfs(TreeNode* root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        if (root->left == NULL && root->right->val > 1) return false;
        if (root->right == NULL && root->left->val > 1) return false;
        if (root->right != NULL && root->left != NULL && abs(root->right->val - root->left->val) > 1) return false;

        return dfs(root->left) && dfs(root->right);

    }

    bool isBalanced(TreeNode* root) {
        count(root);
        return dfs(root);
    }
};