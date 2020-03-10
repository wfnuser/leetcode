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
    int ans = 1;

    int findMaxLength(TreeNode* root) {
        if (root == NULL) return 0;

        int left = findMaxLength(root->left);
        int right = findMaxLength(root->right);
        ans = max(ans, left + right + 1);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        findMaxLength(root);

        return ans - 1;
    }
};