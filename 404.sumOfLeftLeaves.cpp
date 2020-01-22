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
    int sumHelper(TreeNode* root, bool isLeft) {
        if (root == NULL) return 0;
        if (root->right == NULL && root->left == NULL) {
            if (isLeft) return root->val;
        }
        return sumHelper(root->left, true) + sumHelper(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return sumHelper(root, false);
    }
};