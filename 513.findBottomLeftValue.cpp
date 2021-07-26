/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val;
        int depth = 0;
        dfs(root, ans, 0, depth);
        return ans;
    }
    
    void dfs(TreeNode* root, int& ans, int depth, int& maxDepth) {
        if (root == NULL) return;
        if (depth > maxDepth) {
            maxDepth = depth;
            ans = root->val;
        }
        dfs(root->left, ans, depth+1, maxDepth);
        dfs(root->right, ans, depth+1, maxDepth);
    }
};
