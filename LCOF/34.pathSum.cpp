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

    void dfs(TreeNode* root, int sum, vector<int>& path) {
        sum -= root->val;
        path.push_back(root->val);
        if (sum == 0) {
            if (root->left == NULL && root->right == NULL) {
                ans.push_back(path);
                path.pop_back();
                return;
            }
        } 
        
        if (root->left) dfs(root->left, sum, path);
        if (root->right) dfs(root->right, sum, path);
        
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) return ans;

        vector<int> path;
        dfs(root, sum, path);

        return ans;
    }
};