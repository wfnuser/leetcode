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
    int ans;

    void dfs(TreeNode* node, int sum) {
        sum = sum*10 + node->val;
        if (node->left == NULL && node->right == NULL) ans += sum;

        if (node->left != NULL) dfs(node->left, sum);
        if (node->right != NULL) dfs(node->right, sum);
    }

    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        dfs(root, 0);
        return ans;
    }
};