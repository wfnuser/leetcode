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
    int maxLevel = -1;

    void dfs(TreeNode* node, int level) {
        if (node == NULL) return;
        dfs(node->left, level+1);
        dfs(node->right, level+1);
        ans[maxLevel-level-1].push_back(node->val);
    }

    int getMaxLevel(TreeNode* root) {
        if (root == NULL) return 0;
        return max(getMaxLevel(root->left), getMaxLevel(root->right)) + 1;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        maxLevel = getMaxLevel(root);
        ans = vector<vector<int>>(maxLevel, vector<int>());
        dfs(root, 0);

        return ans;  
    }
};