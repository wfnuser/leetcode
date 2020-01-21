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
    int ans = 0;

    void dfs(TreeNode* root) {
        if (root == NULL) return;
        ans++;
        dfs(root->left);
        dfs(root->right);
    }

    int countNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
};