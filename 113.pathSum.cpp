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

    vector<vector<int>> ans;

    void dfs(TreeNode* root, int sum, vector<int> path) {
        if (root == NULL) return;
        sum -= root->val;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL && sum == 0) {
            ans.push_back(path);
        }
        if (root->left != NULL) dfs(root->left, sum, path);
        if (root->right != NULL) dfs(root->right, sum, path);

    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) return ans;
        dfs(root, sum, vector<int>());
        return ans;
    }
};