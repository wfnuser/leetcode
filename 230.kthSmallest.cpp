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
    int cnt = 0;
    int ans;
    bool found = false;
    void dfs(TreeNode* root, int k) {
        if (found) return;
        if (root == NULL) return;
        dfs(root->left, k);
        cnt++;
        if (cnt == k) {
            ans = root->val;
            found = true;
        } 
        dfs(root->right, k);
    };

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);

        return ans;
    }
};